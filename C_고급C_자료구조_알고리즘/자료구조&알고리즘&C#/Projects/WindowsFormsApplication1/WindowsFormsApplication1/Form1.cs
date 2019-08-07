using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        private object browser;

        public Form1()
        {
            InitializeComponent();
            startDateTime = DateTime.Now;
                
        }
        DateTime startDateTime;
        public DateTime GetStartDateTime()
        {
            return startDateTime;
        }

        private void button1_Click(object sender,EventArgs e)
        {
            MessageBox.Show(GetStartDateTime().ToString());
        }
    }
}
