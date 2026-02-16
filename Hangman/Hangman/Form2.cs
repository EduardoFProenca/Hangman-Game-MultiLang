using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Hangman
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
            AtualizarForca();
            InicializarJogo();
            CriarBotoesLetras();
            CriarEspacosLetras();
        }


        private int erros = 0;
        private string palavraSecreta = "COMPUTADOR"; // Palavra a adivinhar
        private string palavraAtual = ""; // Letras descobertas
        private Button[] botoesLetras = new Button[26]; // Array dos 26 botões



        private void InicializarJogo()
        {
            // Cria a palavra com underscores
            palavraAtual = new string('_', palavraSecreta.Length);

            // Ativa captura de teclas
            this.KeyPreview = true;
            //this.KeyPress += Form2_KeyPress;
        }

        private void CriarEspacosLetras()
        {
            int x = 205; // Posição inicial X
            int y = 200; // Posição inicial Y

            for (int i = 0; i < palavraSecreta.Length; i++)
            {
                Label lbl = new Label();
                lbl.Text = "_";
                lbl.Font = new Font("Arial", 24, FontStyle.Bold);
                lbl.Size = new Size(40, 40);
                lbl.Location = new Point(x, y);
                lbl.Name = "lblLetra" + i;
                lbl.TextAlign = ContentAlignment.MiddleCenter;
                lbl.BorderStyle = BorderStyle.FixedSingle;

                this.Controls.Add(lbl);

                x += 50; // Espaçamento entre letras
            }
        }

        private void CriarBotoesLetras()
        {
            string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            int x = 50;  // Posição X inicial
            int y = 280; // Posição Y inicial
            int largura = 40;
            int altura = 40;
            int espacamento = 5;
            int botoesPorLinha = 13; // 13 botões por linha

            for (int i = 0; i < 26; i++)
            {
                Button btn = new Button();
                btn.Text = alfabeto[i].ToString();
                btn.Name = "btn" + alfabeto[i];
                btn.Size = new Size(largura, altura);
                btn.Font = new Font("Arial", 12, FontStyle.Bold);
                btn.BackColor = Color.LightBlue;

                // Posição do botão
                int coluna = i % botoesPorLinha;
                int linha = i / botoesPorLinha;
                btn.Location = new Point(x + (coluna * (largura + espacamento)),
                                         y + (linha * (altura + espacamento)));


                // Adiciona ao formulário
                this.Controls.Add(btn);
                botoesLetras[i] = btn;
            }
        }


        private void AtualizarForca()
        {
            switch (erros)
            {
                case 0:
                    picForca.Image = Properties.Resources.FORCA_0;
                    break;
                case 1:
                    picForca.Image = Properties.Resources.FORCA_1;
                    break;
                case 2:
                    picForca.Image = Properties.Resources.FORCA_2;
                    break;
                case 3:
                    picForca.Image = Properties.Resources.FORCA_3;
                    break;
                case 4:
                    picForca.Image = Properties.Resources.FORCA_4;
                    break;
                case 5:
                    picForca.Image = Properties.Resources.FORCA_5;
                    break;
                case 6:
                    picForca.Image = Properties.Resources.FORCA_6;
                    MessageBox.Show("Você perdeu!");
                    break;
            }
        }



        // Chame este método quando o jogador errar uma letra
        private void AdicionarErro()
        {
            erros++;
            AtualizarForca();
        }
        private void btnA_Click(object sender, EventArgs e)
        {

        }


        private void btnVoltar_Click_1(object sender, EventArgs e)
        {
            Form1 telaJogo = new Form1();
            telaJogo.Show();
            this.Hide();
        }
    }
}
