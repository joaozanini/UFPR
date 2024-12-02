program N03JoaoZanini;

uses noite;

const
  MESES: array[1..12] of string = (
    'JANEIRO', 'FEVEREIRO', 'MARÇO', 'ABRIL', 'MAIO', 'JUNHO',
    'JULHO', 'AGOSTO', 'SETEMBRO', 'OUTUBRO', 'NOVEMBRO', 'DEZEMBRO'
  );

var
  dia, mes, ano, resp: integer;
  dataValida: boolean;

begin
  repeat
    leia('Digite o dia: ', dia);
    leia('Digite o mês: ', mes);
    leia('Digite o ano: ', ano);

    dataValida := valdataf(dia, mes, ano);

    if dataValida then
    begin
      writeln('CURITIBA, ', dia, ' DE ', MESES[mes], ' DE ', ano);
    end
    else
    begin
      writeln('Data inválida. Tente novamente.');
    end;

    // Pergunta ao usuário se ele deseja continuar
    writeln('QUER CONTINUAR? 1 SIM, OUTRO NÚMERO NÃO');
    read(resp);
  until resp <> 1;

  // Finalizar o programa
  termine;
end.
