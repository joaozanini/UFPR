Program N06JOAOZ;
USES NOITE;
// FEITO POR João Vitor Zanini Pedro
VAR
  ARQ: TEXT; 
  FREQ: ARRAY[1..60] OF INTEGER;
  REG: STRING[23];
  NUS, TOT, A, B, Dezena: INTEGER;

// Função para converter uma string para inteiro
function StringParaInt(S: STRING): INTEGER;
var
  Codigo, Valor: INTEGER;
begin
  Val(S, Valor, Codigo);
  if Codigo = 0 then
    StringParaInt := Valor
  else
    StringParaInt := 0;  // Retorna 0 caso de erro na conversão
end;

procedure ContarFrequenciaDezenas();
begin
  // Extrai cada dezena da string REG e incrementa a frequência correspondente
  Dezena := StringParaInt(Copy(REG, 6, 3));  // Primeira dezena
  Inc(FREQ[Dezena]);

  Dezena := StringParaInt(Copy(REG, 9, 3));  // Segunda dezena
  Inc(FREQ[Dezena]);

  Dezena := StringParaInt(Copy(REG, 12, 3)); // Terceira dezena
  Inc(FREQ[Dezena]);

  Dezena := StringParaInt(Copy(REG, 15, 3)); // Quarta dezena
  Inc(FREQ[Dezena]);

  Dezena := StringParaInt(Copy(REG, 18, 3)); // Quinta dezena
  Inc(FREQ[Dezena]);

  Dezena := StringParaInt(Copy(REG, 21, 3)); // Sexta dezena
  Inc(FREQ[Dezena]);
end;

Begin
  ASSIGN(ARQ, 'D_MEGAS.TXT');
  RESET(ARQ);
  
  // Inicializa o contador de frequência para cada dezena com zero
  FOR A := 1 TO 60 DO
    FREQ[A] := 0;

  A := 0; // Contador para o número de registros lidos
  WHILE NOT (EOF(ARQ)) DO
  BEGIN
    A := A + 1;
    READLN(ARQ, REG);
    ContarFrequenciaDezenas(); // Chama a função para contar as dezenas
  END;

  WRITELN('LIDOS=>', A:20);
  WRITELN;
  WRITELN('DEZ FRE    DEZ FRE    DEZ FRE    DEZ FRE    DEZ FRE    DEZ FRE');
  
  FOR A := 1 TO 10 DO
  BEGIN
    WRITE  (A+00:3, FREQ[A+00]:4, '    ', A+10:3, FREQ[A+10]:4, '    ',
            A+20:3, FREQ[A+20]:4, '    ', A+30:3, FREQ[A+30]:4, '    ',
            A+40:3, FREQ[A+40]:4, '    ', A+50:3, FREQ[A+50]:4);
    WRITELN;
  END;

  CLOSE(ARQ);
  TERMINE;
End.
