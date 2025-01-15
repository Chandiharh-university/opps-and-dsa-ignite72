// DOM elements
const carCountElement = document.getElementById("car-count");
const redLight = document.getElementById("red-light");
const yellowLight = document.getElementById("yellow-light");
const greenLight = document.getElementById("green-light");
const carInput = document.getElementById("car-input");

let simulationInterval = null; // For controlling simulation mode

// Update traffic lights based on car count
function updateTrafficLights(carCount) {
  // Reset all lights
  redLight.classList.remove("active");
  yellowLight.classList.remove("active");
  greenLight.classList.remove("active");

  // Logic for which light to activate
  if (carCount < 10) {
    greenLight.classList.add("active");
  } else if (carCount < 30) {
    yellowLight.classList.add("active");
  } else {
    redLight.classList.add("active");
  }
}

// Manual update for car count
function manualUpdate() {
  const carCount = parseInt(carInput.value, 10);
  if (isNaN(carCount)) {
    alert("Please enter a valid number");
    return;
  }
  carCountElement.textContent = carCount;
  updateTrafficLights(carCount);
}

// Simulate car count updates
function simulateTraffic() {
  const carCount = Math.floor(Math.random() * 50); // Random number between 0 and 50
  carCountElement.textContent = carCount;
  updateTrafficLights(carCount);
}

// Toggle simulation mode
function toggleSimulation() {
  if (simulationInterval) {
    clearInterval(simulationInterval);
    simulationInterval = null;
    alert("Simulation stopped!");
  } else {
    simulationInterval = setInterval(simulateTraffic, 3000);
    alert("Simulation started!");
  }
}

// Initialize with default state
updateTrafficLights(0);
