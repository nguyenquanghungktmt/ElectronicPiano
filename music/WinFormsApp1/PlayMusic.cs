using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace WinFormsApp1
{
    public partial class PlayMusic : Form
    {
        SerialPort _serialPort = new SerialPort();
        IDictionary<string, string> musicCode = new Dictionary<string, string>();

        public PlayMusic()
        {
            _serialPort.PortName = "COM6";
            _serialPort.BaudRate = 9600;
            _serialPort.Open();
            InitializeComponent();
            lblText1.Text = "";
            lblText2.Text = "";
            musicCode.Add("Q", "C4");
            musicCode.Add("W", "D4");
            musicCode.Add("E", "E4");
            musicCode.Add("R", "F4");
            musicCode.Add("T", "G4");
            musicCode.Add("Y", "A4");
            musicCode.Add("U", "B4");
            musicCode.Add("A", "C5");
            musicCode.Add("S", "D5");
            musicCode.Add("D", "E5");
            musicCode.Add("F", "F5");
            musicCode.Add("G", "G5");
            musicCode.Add("H", "A5");
            musicCode.Add("J", "B5");
            musicCode.Add("Z", "C6");
            musicCode.Add("X", "D6");
            musicCode.Add("C", "E6");
            musicCode.Add("V", "F6");
            musicCode.Add("B", "G6");
            musicCode.Add("N", "A6");
            musicCode.Add("M", "B6");
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            string dataSending = e.KeyData.ToString();

            lblText2.Text = lblText2.Text + convertKeyPressToMusicalCode(dataSending) + "-";

            _serialPort.Write(dataSending.ToLower());
        }

        private void Form1_Closing(object sender, CancelEventArgs e)
        {
            _serialPort.Close();
        }

        private string convertKeyPressToMusicalCode(string keyPress)
        {
            try
            {
                return musicCode[keyPress];
            }
            catch
            {
                return "C4";
            }
        }

    }
}
