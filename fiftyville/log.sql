-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Search for the description of the incident from reports
SELECT * FROM crime_scene_reports WHERE description LIKE '%duck%';
SELECT * FROM crime_scene_reports
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND street = 'Humphrey Street';

-- | 295 | 2021 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

-- interview transcripts of the witnesses
SELECT * FROM interviews WHERE transcript LIKE '%bakery%' AND year = 2021 AND month = 7 AND day = 28;

-- | 161 | Ruth    | 2021 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- | 162 | Eugene  | 2021 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- | 163 | Raymond | 2021 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |

-- get plate numbers of cars that exited the parking lot at the day of the theft 10:15 am
SELECT *
    FROM bakery_security_logs
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND activity = 'exit'
    AND hour = 10
    AND minute BETWEEN 15 AND 25;

-- people who withdrew money at an ATM on Leggett Street
SELECT *
    FROM atm_transactions
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw';

-- people who talked for less than a minute at the day of theft

SELECT *
    FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60;

-- earliest flight out of Fiftyville
SELECT f.id, f.origin_airport_id, f.destination_airport_id
    FROM flights f
    JOIN airports a ON f.origin_airport_id = a.id
    WHERE a.city = 'Fiftyville'
    AND year = 2021
    AND month = 7
    AND day = 29
    ORDER BY hour
    LIMIT 1;

-- +----+-------------------+------------------------+
-- | id | origin_airport_id | destination_airport_id |
-- +----+-------------------+------------------------+
-- | 36 | 8                 | 4                      |
-- +----+-------------------+------------------------+

-- person on the other end of the phone who purchased the flight ticket.

-- The THIEF is:
SELECT DISTINCT p.name
    FROM people AS p
    -- match license plates of bakery and registered license plates
    JOIN bakery_security_logs AS bsl
        ON p.license_plate = bsl.license_plate
    -- match phone number of registered phone number to phone number of people who called , 60 secs on the day of theft
    JOIN phone_calls AS pc
        ON p.phone_number = pc.caller
    -- match passport number to flight
    JOIN passengers AS psn
        ON p.passport_number = psn.passport_number
    -- match flight id to flight out of fiftyville
    JOIN flights AS flt
        ON psn.flight_id = flt.id
    -- match bank account to person id
    JOIN bank_accounts AS ba
        ON p.id = ba.person_id
    -- match bank account to atm transactions
    JOIN atm_transactions AS atm
        ON ba.account_number = atm.account_number

    -- that was in the parking lot
    WHERE p.license_plate
        IN (
            SELECT license_plate
            FROM bakery_security_logs
            WHERE year = 2021
            AND month = 7
            AND day = 28
            AND activity = 'exit'
            AND hour = 10
            AND minute BETWEEN 15 AND 25
        )
    -- and in the flight
    AND psn.flight_id = (
        SELECT flt.id
        FROM flights AS flt
        JOIN airports a ON flt.origin_airport_id = a.id
        WHERE a.city = 'Fiftyville'
        AND year = 2021
        AND month = 7
        AND day = 29
        ORDER BY hour
        LIMIT 1
    )
    -- called for less than 60 sec
    AND p.phone_number IN (
        SELECT pc.caller
        FROM phone_calls AS pc
        WHERE year = 2021
        AND month = 7
        AND day = 28
        AND duration < 60
    )
    ;

-- accomplice is the phone number bruce called

SELECT p.name
  FROM p
 WHERE p.phone_number