const timer = document.getElementById("timer");
const startButton = document.getElementById("start");
const stopButton = document.getElementById("stop");
const resetButton = document.getElementById("reset");
 
let startTime = 0;
let elapsedTime = 0;
let timerInterval;
 
function formatTimer(milliseconds) {
  const hours = Math.floor(milliseconds / 3_600_000);
  const minutes = Math.floor((milliseconds % 3_600_000) / 60_000);
  const seconds = Math.floor((milliseconds % 60_000) / 1_000);
  const centiseconds = Math.floor((milliseconds % 1_000) / 10);
  return [hours, minutes, seconds]
    .map((unit) => String(unit).padStart(2, "0"))
    .join(":") + `.${String(centiseconds).padStart(2, "0")}`;
}
 
function render() {
  timer.textContent = formatTimer(elapsedTime);
}
 
function startTimer() {
  startTime = Date.now() - elapsedTime;
  timerInterval = setInterval(() => {
    elapsedTime = Date.now() - startTime;
    render();
  }, 10);
  startButton.disabled = true;
  stopButton.disabled = false;
}
 
function stopTimer() {
  clearInterval(timerInterval);
  startButton.disabled = false;
  stopButton.disabled = true;
}
 
function resetTimer() {
  clearInterval(timerInterval);
  elapsedTime = 0;
  render();
  startButton.disabled = false;
  stopButton.disabled = true;
}
 
startButton.addEventListener("click", startTimer);
stopButton.addEventListener("click", stopTimer);
resetButton.addEventListener("click", resetTimer);