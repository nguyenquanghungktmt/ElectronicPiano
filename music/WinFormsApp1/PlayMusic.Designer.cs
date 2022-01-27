
namespace WinFormsApp1
{
    partial class PlayMusic
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.lblText1 = new System.Windows.Forms.RichTextBox();
            this.lblText2 = new System.Windows.Forms.RichTextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // lblText1
            // 
            this.lblText1.Location = new System.Drawing.Point(106, 12);
            this.lblText1.Name = "lblText1";
            this.lblText1.Size = new System.Drawing.Size(565, 93);
            this.lblText1.TabIndex = 0;
            this.lblText1.Text = "";
            // 
            // lblText2
            // 
            this.lblText2.Location = new System.Drawing.Point(106, 123);
            this.lblText2.Name = "lblText2";
            this.lblText2.ReadOnly = true;
            this.lblText2.Size = new System.Drawing.Size(565, 87);
            this.lblText2.TabIndex = 0;
            this.lblText2.Text = "";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(32, 46);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(45, 20);
            this.label1.TabIndex = 1;
            this.label1.Text = "Phím:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(32, 155);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(68, 20);
            this.label2.TabIndex = 2;
            this.label2.Text = "Mã nhạc:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(683, 222);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.lblText2);
            this.Controls.Add(this.lblText1);
            this.KeyPreview = true;
            this.Name = "Form1";
            this.Text = "Form1";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RichTextBox lblText1;
        private System.Windows.Forms.RichTextBox lblText2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
    }
}

