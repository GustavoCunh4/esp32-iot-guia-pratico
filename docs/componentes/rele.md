# Módulo relé de um canal

O exemplo testa somente o indicador/comutação mecânica do módulo, **sem carga nos terminais COM/NO/NC**.

| Lado de controle | Função |
|---|---|
| VCC | Alimentação definida pelo módulo, frequentemente 5 V |
| GND | Terra |
| IN | GPIO de saída digital |

Usa **1 GPIO digital**. Muitos módulos são ativos em LOW; outros não reconhecem 3,3 V corretamente. Confirme datasheet, transistor/optoacoplador e jumper do módulo.

O código possui `RELE_ATIVO_EM_LOW`. Não conecte rede elétrica. Trabalhar com tensão de tomada exige projeto, proteção, caixa e profissional qualificado.
