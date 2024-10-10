Program N01JOAOV;
// Feito por João Vitor Zanini Pedro - GRR20242373
var
  mes, ano: integer;
  
Begin
  repeat
    repeat
      writeln('Digite um mês (1 a 12) ou 0 para encerrar => ');
      readln(mes);
      if (mes < 0) or (mes > 12) then
        writeln('Mês inválido! Por favor, insira um valor entre 1 e 12 ou 0 para encerrar.');
    until (mes >= 0) and (mes <= 12);
    
    if (mes = 0) then
      break;

    repeat
      writeln('Digite um ano (positivo) => ');
      readln(ano);
      if (ano < 1) then
        writeln('Ano inválido! Por favor, insira um ano maior que 0.');
    until (ano > 0); 

    if (mes = 2) then
    Begin
      if (ano mod 4 = 0) and ((ano mod 100 <> 0) or (ano mod 400 = 0)) then
        writeln('Dias máximos: 29 (ano bissexto)')
      else
        writeln('Dias máximos: 28');
    End
    else if (mes in [1, 3, 5, 7, 8, 10, 12]) then
      writeln('Dias máximos: 31')
    else
      writeln('Dias máximos: 30');
    
  until mes = 0;

  writeln('Programa encerrado. Pressione Enter para sair.');
  readln();
End.
