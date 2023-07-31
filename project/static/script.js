document.getElementById("python").addEventListener("click", function() {
    sendPostRequest('python');
});

document.getElementById("java").addEventListener("click", function() {
    sendPostRequest('card2');
});

function sendPostRequest(cardId) {
    fetch('/list', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({
            card: cardId
        })
    })
}