// Only change code below this line
class Thermostat {
  constructor(temperature){ //F
    this._temperature = temperature;
  }
  //getter (Celsius)
  get temperature(){ 
    return (5/9 * (this._temperature -32));
    }
  //setter (C)
  set temperature(temp){
    this._temperature = temp * 9.0 / 5 + 32;
  }
}
// Only change code above this line

const thermos = new Thermostat(76); // Setting in Fahrenheit scale
let temp = thermos.temperature; // 24.44 in Celsius
thermos.temperature = 26;
console.log(temp);
temp = thermos.temperature; // 26 in Celsius
console.log(temp);