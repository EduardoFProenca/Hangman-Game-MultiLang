import javax.swing.JOptionPane;

public class Hangman {

    public static void main(String[] args) {
        String alfabeto = "<html><pre> Letras disponiveis: A-B-C-D-E-F-G-H-I-J-K-L-M-N-O-P-Q-R-S-T-U-V-W-X-Y-Z </pre></html>";
        String alfabetoDisponivel = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int vidas = 8;
        int opcaoMenu;
        String letrasReveladas = "";

        opcaoMenu = Integer.parseInt(JOptionPane.showInputDialog(
                "Bem-vindo ao Jogo da Forca\n1 - Jogar (definir palavra)\n2 - Jogar (palavra automatica)\n3 - Sair"));

        if (opcaoMenu != 3) {
            if (opcaoMenu == 1) {
                String palavraSecreta = JOptionPane.showInputDialog("Digite a palavra secreta: ").toUpperCase();
                
                for (int i = 0; i < palavraSecreta.length(); i++) {
                    letrasReveladas += "[_] ";

                }
                
            }
            System.out.println(letrasReveladas);
            /*
             * String entrada =
             * JOptionPane.showInputDialog("Digite a letra: ").toUpperCase();
             * char letra = entrada.charAt(0);
             * 
             * Object[] opcoes = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
             * 'L', 'M',
             * 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
             * char letras = (Character) JOptionPane.showInputDialog(
             * null,
             * "Escolha a letra:",
             * "Seleção",
             * JOptionPane.QUESTION_MESSAGE,
             * null,
             * opcoes,
             * opcoes[0]);
             */
            String forca = "<html><pre>" +
                    " _______<br>" +
                    " |     |<br>" +
                    " |     " + (vidas < 8 ? "O" : "") + "<br>" +
                    " |    " +
                    (vidas == 6 ? " | " : vidas == 5 ? "/|" : vidas <= 4 ? "/|\\" : "") + "<br>" +
                    " |   " +
                    (vidas == 3 ? " /" : vidas == 2 ? " / \\" : vidas == 1 ? "_/ \\" : vidas == 0 ? "_/ \\_" : "")
                    + "<br>" +
                    " |<br>" +
                    "_|_</pre></html>";

            JOptionPane.showMessageDialog(null, forca + "<br>Palavra: " + letrasReveladas + "<br>" + alfabeto, "Jogo da Forca",
                    JOptionPane.PLAIN_MESSAGE);
        }

    }

}