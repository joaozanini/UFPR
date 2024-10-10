Program N02JOAOV ;
// feito por Jo�o Vitor Zanini Pedro GRR20242373 - TRABALHO02
uses NOITE;
var diaHoje, mesHoje, anoHoje, bdayDia, bdayMes, bdayAno: integer;
var diasVividos, mesesVividos, anosVividos: integer;
Begin

// anivers�rio do usu�rio
repeat
	begin
		writeln('Dia do seu anivers�rio =>');
		readln(bdayDia);
		writeln('M�s do seu anivers�rio =>');
		readln(bdayMes);
		writeln('Ano do seu anivers�rio =>');
		readln(bdayAno);
	end;
until valdataf(bdayDia, bdayMes, bdayAno);

// data atual
repeat
	begin
		writeln('Dia de hoje =>');
		readln(diaHoje);
		writeln('M�s da data de hoje =>');
		readln(mesHoje);
		writeln('Ano da data de hoje =>');
		readln(anoHoje);
	end;
until valdataf(diaHoje, mesHoje, anoHoje);	

// calc. tempo de vida
diasVividos := diaHoje - bdayDia;
mesesVividos := mesHoje - bdayMes;
anosVividos := anoHoje - bdayAno;

// case: diasVividos || mesesVividos < 0
// diasVividos < 0
if (diasVividos < 0) then
	begin
		mesesVividos := mesesVividos - 1;
		diasVividos := diasVividos + diamaxm(mesHoje-1, anoHoje);
	end;
	
// mesesVividos < 0;
if (mesesVividos < 0) then
	begin
		mesesVividos := mesesVividos + 12;
		anosVividos := anosVividos -1;
	end;
		
// result
writeln('Voc� viveu por: ', anosVividos, ' anos, ', mesesVividos, ' m�ses e ', diasVividos, ' dias.' );		

// end.
termine;
End.                