namespace Test
{
    using System.IO.Ports;
    using static System.Windows.Forms.VisualStyles.VisualStyleElement;
    using System.Threading.Tasks;
    public partial class Form1 : Form
    {
        SerialPort serialPort1;
        string dataOut;
        bool framestarted = false;
        string currentFrame = "";

        public Form1()
        {
            InitializeComponent();
            // Done with starting Form
            string[] ports = SerialPort.GetPortNames();
            comboBox1.Items.AddRange(ports);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Connect
            serialPort1 = new SerialPort(comboBox1.SelectedItem.ToString());
            //serialPort1.PortName = comboBox1.Text; //not working
            serialPort1.DataReceived += new SerialDataReceivedEventHandler(Port_DataReceived);
   
            serialPort1.BaudRate = Convert.ToInt32(comboBox2.Text);
            serialPort1.DataBits = Convert.ToInt32(comboBox3.Text);
            serialPort1.StopBits = (StopBits)Enum.Parse(typeof(StopBits), comboBox4.Text);
            serialPort1.Parity = (Parity)Enum.Parse(typeof(Parity), comboBox5.Text);

            try
            {
                if (!serialPort1.IsOpen)
                {
                    serialPort1.Open();
                    label6.Text = "Connected";
                    label6.ForeColor = Color.Green;
                }
            }
            catch (Exception err)
            {
                MessageBox.Show(err.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                throw;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // Disconnect
            if (serialPort1.IsOpen == true)
            {
                serialPort1.Close();
                label6.Text = "Disconnected";
                label6.ForeColor = Color.Red;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            // Send
            if (serialPort1.IsOpen == true)
            {
                dataOut = textBox1.Text;
                //serialPort1.WriteLine(dataOut);
                //serialPort1.WriteLine("hi");
                serialPort1.Write(dataOut);
                textBox1.Clear();
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            comboBox1.DataSource = SerialPort.GetPortNames();
        }

        private void Port_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            //Task.Delay(500);
            SerialPort serialPort = (SerialPort)sender;
            string receivedData = serialPort.ReadExisting();
            
            int indx_start = receivedData.IndexOf('*');
            int indx_end = receivedData.IndexOf(';');


            if (indx_end >= 0 && framestarted)
            {
                framestarted = false;
                currentFrame += receivedData.Substring(0, indx_end);

                this.Invoke(new System.Action(() =>
                {
                    char characterAtIndex1 = currentFrame[0];
                    switch (characterAtIndex1)
                    {
                        case '0':
                            currentFrame = currentFrame.Substring(1);
                            label13.Text = currentFrame;
                            break;
                        case '1':
                            currentFrame = currentFrame.Substring(1);
                            label14.Text = currentFrame;
                            break;
                        case '2':
                            currentFrame = currentFrame.Substring(1);
                            label15.Text = currentFrame;
                            break;
                        default:
                            label7.Text = currentFrame;
                            break;
                    }

                }));

            }

            if (framestarted)
            {
                currentFrame += receivedData;
            }

            if (indx_start >= 0 && !framestarted)
            {
                currentFrame = "";
                framestarted = true;

                if (receivedData.Length > indx_start + 1)
                {
                    currentFrame += receivedData.Substring(indx_start + 1);
                }
            }

        }

        private void button5_Click(object sender, EventArgs e)
        {
            // Open
            if (serialPort1.IsOpen == true)
            {
                serialPort1.Write("0");
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            // Close
            if (serialPort1.IsOpen == true)
            {
                serialPort1.Write("1");
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            // Activate
            if (serialPort1.IsOpen == true)
            {
                serialPort1.Write("2");
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            // Deactivate
            if (serialPort1.IsOpen == true)
            {
                serialPort1.Write("3");
            }
        }
    }
}
