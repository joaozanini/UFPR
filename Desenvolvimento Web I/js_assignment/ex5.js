function contarChar(str, char) {
  let contador = 0;
  for (let i = 0; i < str.length; i++) {
    if (str[i] === char) {
      contador++;
    }
  }
  return contador;
}

let str = "Aula de web1";
console.log(contarChar(str, "s"));