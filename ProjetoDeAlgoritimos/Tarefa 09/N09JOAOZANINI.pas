PROGRAM N09JOAOZANINI;
//FEITO POR JOÃO VITOR ZANINI PEDRO - GRR20242373

USES NOITE;
CONST
  NOMEDISCIPLINA: ARRAY[1..6] OF STRING[20] = ('L.E.M               ', 
                                               'MATEMÁTICA          ', 
                                               'LÓGICA              ',
                                               'CONHECIMENTO ESPEC. ', 
                                               'INFORMÁTICA         ', 
                                               'ATUALIDADES         ');
TYPE
  TCANDIDATO = REGIS;
  TVETOR = VETOR;

VAR
  ARQCAND: FILE OF TCANDIDATO;
  ARQNOTAS: TEXT;
  REG: TCANDIDATO;
  LISTA: TVETOR;
  SOMADISCIPLINA: ARRAY[1..6] OF INTEGER;
  INSC, INSCA, NOTASTR, LINHANOTA: STRING[35];
  INDICEV, A, B, E, TOTCAR, TOT, TT, POSI, NOTA, SOMATOTAL: INTEGER;
  MEDIA: REAL;
  
BEGIN
  TEXTBACKGROUND(0);
  CLRSCR;
  TEXTCOLOR(15);
  ASSIGN(ARQCAND, 'CAND.IND');
  ASSIGN(ARQNOTAS, 'NOTAS.TXT');
  RESET(ARQCAND);
  RESET(ARQNOTAS);
  
  
  REPEAT
    READ(ARQCAND, REG);
    INDICEV := A + 1;
    LISTA[INDICEV].PF := A;
    STR(REG.NUM, INSC);
    TOTCAR := LENGTH(INSC);
    FOR B := 1 TO 4 - TOTCAR DO
      INSERT('0', INSC, 1);
    LISTA[INDICEV].CC := INSC;
    A := A + 1;
  UNTIL EOF(ARQCAND);
  
	TOT := INDICEV;
  
	WRITELN('Lendo NOTAS.TXT, aguarde...');
  
	ORDEM(LISTA, TOT);
  FOR A := 1 TO 6 DO
    SOMADISCIPLINA[A] := 0;
  
	WRITELN('Registrando notas, aguarde...');
  
	REPEAT
    TT := TT + 1;
    READLN(ARQNOTAS, LINHANOTA);
    INSCA := COPY(LINHANOTA, 1, 4);
    PEBIN1(LISTA, INSCA, TOT, POSI);
    SEEK(ARQCAND, LISTA[POSI].PF);
    READ(ARQCAND, REG);
    B := 6;
    SOMATOTAL := 0;
    FOR A := 1 TO 6 DO
    BEGIN
      NOTASTR := COPY(LINHANOTA, B, 3);
      VAL(NOTASTR, NOTA, E);
      IF E = 0 THEN
      BEGIN
        REG.NOTAS[A] := NOTA;
        SOMATOTAL := SOMATOTAL + NOTA;
        SOMADISCIPLINA[A] := SOMADISCIPLINA[A] + NOTA;
      END;
      B := B + 4;
    END;
    REG.SOM := SOMATOTAL;    
    SEEK(ARQCAND, LISTA[POSI].PF);
    WRITE(ARQCAND, REG);
  UNTIL EOF(ARQNOTAS);
  
	WRITELN('Notas lidas e registradas!');
  WRITELN('Média das disciplinas:');
  WRITELN('DISCIPLINA               MÉDIA');
  FOR A := 1 TO 6 DO
  
	BEGIN
    MEDIA := SOMADISCIPLINA[A] / TOT;
    WRITELN(NOMEDISCIPLINA[A], MEDIA:10:2);
  END;
  TERMINE;
  CLOSE(ARQCAND);
  CLOSE(ARQNOTAS);
END.
