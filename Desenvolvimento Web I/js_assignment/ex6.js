function verificarSubstring(str, substr) {
  for (let i = 0; i <= str.length - substr.length; i++) {
    let encontrado = true;

    for (let j = 0; j < substr.length; j++) {
      if (str[i + j] !== substr[j]) {
        encontrado = false;
        break;
      }
    }

    if (encontrado) {
      return i;
    }
  }

  return -1;
}

let s = "Aula de web1";
console.log(verificarSubstring(s, "web1")); // -> 8
console.log(verificarSubstring(s, "web2")); // -> -1