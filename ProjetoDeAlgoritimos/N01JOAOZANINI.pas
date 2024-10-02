Program N01JOAOZANINI;
// João Vitor Zanini Pedro - GRR20242373
var
  mes, ano: integer;
  
Begin
  repeat
    writeln('Digite um mes (1 a 12) ou 0 para encerrar => ');
    readln(mes);
    if (mes = 0) then
      exit;
    if (mes < 0) or (mes > 12) then
      writeln('Mês inválido! Por favor, insira um valor entre 1 e 12 ou 0 para encerrar.');
  until (mes >= 1) and (mes <= 12);

  repeat
    writeln('Digite um ano (positivo) => ');
    readln(ano);
    if (ano < 1) then
      writeln('Ano inválido! Por favor, insira um ano maior que 0.');
  until (ano > 0); 

  if (mes = 2) then
  Begin
    if (ano mod 4 = 0) and ((ano mod 100 <> 0) or (ano mod 400 = 0)) then
      writeln('Dias maximos: 29 (ano bissexto)')
    else
      writeln('Dias maximos: 28');
  End
  else if (mes = 1) or (mes = 3) or (mes = 5) or (mes = 7) or (mes = 8) or (mes = 10) or (mes = 12) then
    writeln('Dias maximos: 31')
  else
    writeln('Dias maximos: 30');

  writeln('Enter para encerrar');
  readln();
End.