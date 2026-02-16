namespace Hangman
{
    partial class Form2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label2 = new System.Windows.Forms.Label();
            this.btn = new System.Windows.Forms.Button();
            this.btnVoltar = new System.Windows.Forms.Button();
            this.picForca = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.picForca)).BeginInit();
            this.SuspendLayout();
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Font = new System.Drawing.Font("MingLiU_MSCS-ExtB", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(202)))), ((int)(((byte)(200)))), ((int)(((byte)(186)))));
            this.label2.Location = new System.Drawing.Point(176, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(402, 27);
            this.label2.TabIndex = 1;
            this.label2.Text = "Bem-vindo ao Jogo da Forca";
            // 
            // btn
            // 
            this.btn.Location = new System.Drawing.Point(616, 364);
            this.btn.Name = "btn";
            this.btn.Size = new System.Drawing.Size(122, 58);
            this.btn.TabIndex = 2;
            this.btn.Text = "btnJogar";
            this.btn.UseVisualStyleBackColor = true;
            // 
            // btnVoltar
            // 
            this.btnVoltar.Location = new System.Drawing.Point(616, 287);
            this.btnVoltar.Name = "btnVoltar";
            this.btnVoltar.Size = new System.Drawing.Size(122, 58);
            this.btnVoltar.TabIndex = 3;
            this.btnVoltar.Text = " Voltar";
            this.btnVoltar.UseVisualStyleBackColor = true;
            this.btnVoltar.Click += new System.EventHandler(this.btnVoltar_Click_1);
            // 
            // picForca
            // 
            this.picForca.Location = new System.Drawing.Point(25, 56);
            this.picForca.Name = "picForca";
            this.picForca.Size = new System.Drawing.Size(223, 192);
            this.picForca.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picForca.TabIndex = 4;
            this.picForca.TabStop = false;
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(35)))), ((int)(((byte)(80)))), ((int)(((byte)(122)))));
            this.ClientSize = new System.Drawing.Size(800, 521);
            this.Controls.Add(this.picForca);
            this.Controls.Add(this.btnVoltar);
            this.Controls.Add(this.btn);
            this.Controls.Add(this.label2);
            this.Name = "Form2";
            this.Text = "Form2";
            ((System.ComponentModel.ISupportInitialize)(this.picForca)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btn;
        private System.Windows.Forms.Button  btnVoltar;
        private System.Windows.Forms.PictureBox picForca;
    }
}