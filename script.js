homeScore = 0
guestScore = 0

homeScoreEl = document.getElementById("score-home")
guestScoreEl = document.getElementById("score-guest")

function homePlusOne() {
    homeScore += 1
    homeScoreEl.innerText = homeScore
}

function homePlusTwo() {
    homeScore += 2
    homeScoreEl.innerText = homeScore
}

function homePlusThree() {
    homeScore += 3
    homeScoreEl.innerText = homeScore
}

function guestPlusOne() {
    guestScore += 1
    guestScoreEl.innerText = guestScore
}

function guestPlusTwo() {
    guestScore += 2
    guestScoreEl.innerText = guestScore
}

function guestPlusThree() {
    guestScore += 3
    guestScoreEl.innerText = guestScore
}