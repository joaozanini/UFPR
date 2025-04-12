function soma(arr) {
  let soma = 0;
  for (i = 0; i < arr.length; i++) {
    soma += arr[i];
  }

  return soma;
}

var a = [1, 2, 3];
console.log(soma(a));
