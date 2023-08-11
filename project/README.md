# チンプンカンプン・Chinpunkanpun
#### Video Demo:  [チンプンカンプン - Chinpunkanpun](https://www.youtube.com/watch?v=NFQ1blxKiEc)
#### Description:
This project plans to solve some challenges when joining a new project as a Japanese Bridge Systems Engineer.
Most of the time, we are expected to know a new topic each time we join a new project.
Along with those are new Japanese Technical Terminologies from Programming Languages, Frameworks and Technologies that the project might use.
Although it is fun to learn new things, it is quite a challenge to find a collated reference for these Japanese words.
That's why using my Web app, **チンプンカンプン**(Chinpunkanpun), a Japanese word that according to a dictionary means "unintelligible language; incoherent language; talking nonsense; "all Greek to me"; double Dutch; (something) incomprehensible; babble; gibberish; jargon; gobbledygook".
I plan to create a convenient and reliable way to learn about these technical words.


#### Things to consider

- What will your software do?<br>
1. It would display Japanese words that are used in Programming languages and technical topics.
2. You can Add new terms to the dictionary.
3. You can search for a Japanese and English word.


- What features will it have?<br>
1. Display in a list of all the terms in English and Japanese.
2. Cards that you can select to quickly display the most used Programming Language and Topics.
3. A search function for either word, term, or topic.
4. Add new terms to the collection of terms.

- How will it be executed?<br>
1. I will be using Python, Flask, HTML, CSS, Bootstrap cards

- What new skills will you need to acquire?<br>
1. Proper implementation of Flask GET and POST.
2. Review Python functions and processes that are used for Data manipulation and storing data.
3. SQL queries and proper ways of making relational database tables.
4. HTML and CSS to properly display my contents to a responsive screen.

- What topics will you need to research?<br>
1. Python Dictionary and List processes.
2. Flask GET and POST.
3. SQL queries, table creation, and primary key usage.
4. HTML and CSS for a clean and easy to use UI.

- If working with one or two classmates, who will do what?<br>
1. I would plan to do this alone, with the help of online resources and CS50 Duck Debugger.

- In the world of software, most everything takes longer to implement than you expect. And so it’s not uncommon to accomplish less in a fixed amount of time than you hope.<br>
- What might you consider to be a good outcome for your project?<br>
1. Properly displays a list of cards and lists of terms relating to each programming language or topic.

- A better outcome?<br>
1. Be able to implement a search function for the words or topic.

- The best outcome?<br>
1. Fancy animations, good background, CSS Styles that is responsive and does not break with different kinds of screen sizes.

#### Project Specifications
##### Function List
|No.|Function Name|Description|
|---|-------------|-----------|
|1  |after_request(response)|From CS50 Finance - Ensure responses aren't cached|
|2  |login()    |From CS50 Finance - Log user in|
|3  |logout()    |From CS50 Finance - Log user out|
|4  |register()   |From CS50 Finance - Register user|
|5  |index()    |Creates database table for the terms list. <br>Renders the template that shows cards that of the most common Programming Language and Topics|
|6  |add_term()    |Add new terms to the database. <br>Renders add term template.|
|7  |list()    |Shows a list of all the terms in the database or a particular topic selected by the user from the cards in the index.|
|8  |apology(message, code=400)    |From CS50 Finance `helpers.py` - Render message as an apology to user.|
|9  |login_required(f)    |From CS50 Finance `helpers.py` - Decorate routes to require login.|
|10  |search()    |Search for a Japanese or English Term or a Topic.|


##### Pages
###### 1. Login
![Login page](/project/static/pages/login.png "Login page")
###### 2. Register
![Register a new user.](/project/static/pages/register.png "HRegister a new user.")
###### 3. Home Page
![Home page with cards!](/project/static/pages/Home.png "Home page with cards!")
###### 4. Terms List
![List of terms!](/project/static/pages/terms_list.png "List of terms.")
###### 5. Add Term
![Add new terms!](/project/static/pages/add_terms.png "Add new terms!")
###### 6. Search
![Search for terms!](/project/static/pages/search.png "Search for terms!")

##### Decisions
1. Using the CS50 Finance distribution code, I was able to easily go and implement what I had in mind, without taking too much time setting up my own flask app base and jinja syntax for the templates.

2. I tried using Javascript to display the items in the list when you select a card from the homepage. However, it was a bit more complicated than I originally thought, so I went with flask and jinja syntax.

3. Bootstrap elements are a bit hard to align, but with the help of CS50 duck debugger, I was able to produce what I originally planned for the layout of my web app.

4. I decided to create 3 tables in my database. A table for the Users, Topics, and for the terms list.

5. Although I wanted to go all out on the functions and style of my app, making it easy to use and clean was the better approach.

6. I am thinking of adding a batch term addition using csv files. Maybe it would be easier to insert items that way.


##### Others
1. This project took me about 2 weeks to make. I allotted about 2 hours a day.
2. Originally, I wanted to make a simple portfolio.
But suddenly got an Idea to make this Dictionary-like web app instead.
Because I would be changing projects again very soon, and would need to research again for words and terms for some new programming language or topics.
