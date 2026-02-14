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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void btnSair_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void btnJogar_Click(object sender, EventArgs e)
        {
            Form2 telaJogo = new Form2();
            telaJogo.Show(); // Abre a nova tela
            this.Hide(); // Esconde o menu principal (opcional)
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
