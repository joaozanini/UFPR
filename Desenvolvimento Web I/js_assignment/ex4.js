function invertArray(arr) {
  let invertedArray = [];
  for (let i = arr.length - 1; i >= 0; i--) {
    invertedArray.push(arr[i]);
  }
  return invertedArray;
}

let arr = [1, 2, 3, 4, 5];
console.log(invertArray(arr));