var currentAudio = null;

function playAudio(name) {
    var audio;
    audio = document.getElementById(name);
    if (currentAudio !== audio && (currentAudio != null)) {
        currentAudio.pause();
    }
    audio.play();
    currentAudio = audio;
}

function stopAudio(name) {
    var audio_;
    audio_ = document.getElementById(name);
    if (currentAudio === audio_) {
        currentAudio.pause();
    }
}

function reAudio(name) {
    var audio__;
    audio__ = document.getElementById(name);
    if (audio__ === currentAudio) {
        currentAudio.currentTime = 0;
    }
}