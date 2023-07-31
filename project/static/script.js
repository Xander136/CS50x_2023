document.getElementById("python").addEventListener("click", function() {
    sendPostRequest('python');
});

document.getElementById("java").addEventListener("click", function() {
    sendPostRequest('java');
});

document.getElementById("cpp").addEventListener("click", function() {
    sendPostRequest('cpp');
});

document.getElementById("javascript").addEventListener("click", function() {
    sendPostRequest('javascript');
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