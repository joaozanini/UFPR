program N04Joao;

const
  MAX_NOTAS = 100;

var
  notas: array[1..MAX_NOTAS] of integer;
  total, i, j, temp: integer;

begin
  total := 0;

  // Leitura e validação das notas
  repeat
    writeln('Digite uma nota entre 0 e 100 (ou uma nota negativa para terminar): ');
    readln(temp);

    if (temp >= 0) and (temp <= 100) then
    begin
      total := total + 1;
      notas[total] := temp;
    end
    else if (temp > 100) then
    begin
      writeln('Nota inválida. Insira um valor entre 0 e 100.');
    end;
  until (temp < 0) or (total = MAX_NOTAS);

  // Ordenação das notas em ordem crescente (Método da Troca)
  for i := 1 to total - 1 do
    for j := i + 1 to total do
      if notas[i] > notas[j] then
      begin
        temp := notas[i];
        notas[i] := notas[j];
        notas[j] := temp;
      end;

  // Exibe as notas menores que 50 em ordem crescente
  writeln('Notas menores que 50 em ordem crescente:');
  for i := 1 to total do
    if notas[i] < 50 then
      writeln(notas[i]);

  // Exibe as notas maiores ou iguais a 50 em ordem decrescente
  writeln('Notas maiores ou iguais a 50 em ordem decrescente:');
  for i := total downto 1 do
    if notas[i] >= 50 then
      writeln(notas[i]);
end.
