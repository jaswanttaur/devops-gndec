const lengthSlider = document.querySelector(".pass-length input"),
  options = document.querySelectorAll(".option input"),
  copyIcon = document.querySelector(".input-box span"),
  checkIcon = document.querySelector(".input-box span.hidden"),
  passwordInput = document.querySelector(".input-box input"),
  passIndicator = document.querySelector(".pass-indicator"),
  strengthIcons = document.querySelectorAll(".strength-icons span"),
  generateBtn = document.querySelector(".generate-btn"),
  saveBtn = document.querySelector(".save-btn");

const characters = {
  lowercase: "abcdefghijklmnopqrstuvwxyz",
  uppercase: "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
  numbers: "0123456789",
  symbols: "^!$%&|[](){}:;.,*+-#@<>~"
}

const generatePassword = () => {
  let staticPassword = "",
    randomPassword = "",
    excludeDuplicate = false,
    passLength = lengthSlider.value;

  options.forEach(option => {
    if (option.checked) {
      if (option.id !== "exc-duplicate" && option.id !== "spaces") {
        staticPassword += characters[option.id];
      } else if (option.id === "spaces") {
        staticPassword += `  ${staticPassword}  `;
      } else {
        excludeDuplicate = true;
      }
    }
  });

  for (let i = 0; i < passLength; i++) {
    let randomChar = staticPassword[Math.floor(Math.random() * staticPassword.length)];
    if (excludeDuplicate) {
      !randomPassword.includes(randomChar) || randomChar == " " ? randomPassword += randomChar : i--;
    } else {
      randomPassword += randomChar;
    }
  }
  passwordInput.value = randomPassword;
}

const updateStrengthIndicator = () => {
  const strengthThresholds = [0.25, 0.5, 0.75];
  const strengthClasses = ["sentiment_very_dissatisfied", "sentiment_dissatisfied", "sentiment_satisfied", "sentiment_very_satisfied"];
  const strength = lengthSlider.value / lengthSlider.max;
  let strengthLevel = 0;

  for (let i = 0; i < strengthThresholds.length; i++) {
    if (strength < strengthThresholds[i]) {
      strengthLevel = i;
      break;
    }
  }

  strengthIcons.forEach((icon, index) => {
    icon.innerText = strengthLevel >= index ? strengthClasses[strengthLevel] : strengthClasses[index];
  });
}

const updateSlider = () => {
  document.querySelector(".pass-length span").innerText = lengthSlider.value;
  generatePassword();
  updateStrengthIndicator();
}

updateSlider();

const copyPassword = () => {
  navigator.clipboard.writeText(passwordInput.value);
  copyIcon.classList.add("hidden");
  checkIcon.classList.remove("hidden");
  setTimeout(() => {
    copyIcon.classList.remove("hidden");
    checkIcon.classList.add("hidden");
  }, 1500);
}

copyIcon.addEventListener("click", copyPassword);
lengthSlider.addEventListener("input", updateSlider);
generateBtn.addEventListener("click", generatePassword);

// Additional Functionality

const togglePasswordVisibility = () => {
  const inputType = passwordInput.type;
  passwordInput.type = inputType === "password" ? "text" : "password";
}

const savePassword = () => {
  // Implement saving or downloading the generated password
}

saveBtn.addEventListener("click", savePassword);
