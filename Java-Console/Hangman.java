import javax.swing.JOptionPane;

public class Hangman {

    public static void main(String[] args) {
        String alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String alfabetoDisponivel = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int vidas = 8;
        int opcaoMenu;

        opcaoMenu = Integer.parseInt(JOptionPane.showInputDialog(
                "Bem-vindo ao Jogo da Forca\n1 - Jogar (definir palavra)\n2 - Jogar (palavra automatica)\n3 - Sair"));

        if (opcaoMenu != 3) {
            if (opcaoMenu == 1) {
                String palavraSecreta = JOptionPane.showInputDialog("Digite a palavra secreta: ").toUpperCase();
                char[] letrasReveladas = new char[palavraSecreta.length()];
            }
          

            String entrada = JOptionPane.showInputDialog("Digite a letra: ").toUpperCase();
            char letra = entrada.charAt(0);

            Object[] opcoes = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
                 'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
            char letras = (Character) JOptionPane.showInputDialog(
                    null,
                    "Escolha a letra:",
                    "Seleção",
                    JOptionPane.QUESTION_MESSAGE,
                    null,
                    opcoes,
                    opcoes[0]);

             String forca = "<html><pre>" +
    " _______<br>" +
    " |     |<br>" +
    " |     " + (vidas < 8 ? "O" : "") + "<br>" +
    " |    " + 
    (vidas == 6 ? " | " : 
     vidas == 5 ? "/|" : 
     vidas <= 4 ? "/|\\" : "") + "<br>" +
    " |   " + 
    (vidas == 3 ? " /" : 
     vidas == 2 ? " / \\" : 
     vidas == 1 ? "_/ \\" : 
     vidas == 0 ? "_/ \\_" : "") + "<br>" +
    " |<br>" +
    "_|_</pre></html>";

JOptionPane.showMessageDialog(null, forca, "Jogo da Forca", JOptionPane.PLAIN_MESSAGE);       
        }

        /*
         * for(int Contador = 1;Contador <= veze ;Contador++){ // Estrutura de repetição
         * FOR, que será executada o número de vezes
         * Nome = JOptionPane.showInputDialog("Nome:");// Solicita o nome do
         * entrevistado
         * Idade= Integer.parseInt(JOptionPane.showInputDialog("Idade: "));// Solicita a
         * idade do entrevistado
         * Opiniao= Integer.parseInt(JOptionPane.
         * showInputDialog("Opinião sobre o atendimento prestado:\n "
         * +"sendo: 1-EXCELENTE, 2-BOM ou 3-RUIM.")); // Solicita a opinião do
         * entrevistado (1-EXCELENTE, 2-BOM, 3-RUIM)
         * 
         * switch (Opiniao){// Estrutura switch para verificar qual foi a opinião dada
         * pelo entrevistado.
         * case 1:// Caso a opinião seja EXCELENTE.
         * Excelente++;// Incrementa a contagem de respostas EXCELENTE.
         * break;// Sai do switch.
         * case 2: // Caso a opinião seja BOM.
         * Bom++;
         * break;
         * case 3:// Caso a opinião seja RUIM.
         * Ruim++;// Incrementa a contagem de respostas RUIM.
         * break;
         * default:// Caso o número inserido seja inválido (fora da faixa de 1 a 3).
         * Contador--; // Decrementa o contador para refazer a coleta do mesmo
         * entrevistado.
         * JOptionPane.showMessageDialog(
         * null,"Valor digitado está incorreto, fora da faixa entre 1 a 3"); // Mostra
         * mensagem de erro.
         * break;
         * }
         * }
         * // Exibe o resultado final da pesquisa com a contagem de EXCELENTE e RUIM.
         * JOptionPane.showMessageDialog(null,"Quantidade de respostas “Excelente”: "
         * +Excelente+ "\nQuantidade de respostas 'Ruim': "+Ruim);
         * //JOptionPane.showMessageDialog(null,"Quantidade de respostas “Bom”: "+Bom);
         * // Exibe o resultado final da pesquisa com BOM.
         */
    }

}