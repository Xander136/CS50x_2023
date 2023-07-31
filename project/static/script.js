document.getElementById("card1").addEventListener("click", function() {
    sendPostRequest('card1');
});

document.getElementById("card2").addEventListener("click", function() {
    sendPostRequest('card2');
});

function sendPostRequest(cardId) {
    fetch('/your-endpoint', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({
            card: cardId
        })
    })
} 