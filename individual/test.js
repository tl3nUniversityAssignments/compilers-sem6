let x = 10; // comment
const PI = 3.14159;
/*
  multi line
  comment
*/
function greet(name) {
  let message = "Hello, " + name + "!";
  if (name === "error") {
    throw new Error("Test error!");
  }
  return message;
}

let y = x / 2;
let z = 1.;
let w = .5;
let obj = { key: "value" };
console.log(obj?.property);
let val = null ?? "default";