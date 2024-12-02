program ValidarCPF;

var
  cpf: string[11];
  vet: array[1..11] of integer;
  i, soma, resto, j, k: integer;

begin
  repeat
    writeln('Digite o CPF (ou "00000000000" para encerrar):');
    readln(cpf);

    if cpf = '00000000000' then
      break;

    // Converte os caracteres do CPF para n�meros
    for i := 1 to 11 do
      vet[i] := Ord(cpf[i]) - Ord('0');

    // C�lculo do primeiro d�gito verificador (J)
    soma := vet[1] * 10 + vet[2] * 9 + vet[3] * 8 + vet[4] * 7 + vet[5] * 6 + vet[6] * 5 + vet[7] * 4 + vet[8] * 3 + vet[9] * 2;
    resto := soma mod 11;
    
    if (resto = 0) or (resto = 1) then
      j := 0
    else
      j := 11 - resto;

    // Verifica se o primeiro d�gito � v�lido
    if j <> vet[10] then
    begin
      writeln('CPF digitado inv�lido. D�gito J calculado: ', j);
      continue;
    end;

    // C�lculo do segundo d�gito verificador (K)
    soma := vet[1] * 11 + vet[2] * 10 + vet[3] * 9 + vet[4] * 8 + vet[5] * 7 + vet[6] * 6 + vet[7] * 5 + vet[8] * 4 + vet[9] * 3 + vet[10] * 2;
    resto := soma mod 11;
    if (resto = 0) or (resto = 1) then
      k := 0
    else
      k := 11 - resto;

    // Verifica se o segundo d�gito � v�lido
    if k <> vet[11] then
    begin
      writeln('CPF digitado inv�lido. D�gito K calculado: ', k);
      continue;
    end;

    // Se ambos os d�gitos forem v�lidos
    writeln('CPF lido v�lido.');
    
  until cpf = '00000000000';
end.
