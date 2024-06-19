namespace Test
{
    partial class Form1
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
            comboBox1 = new ComboBox();
            comboBox2 = new ComboBox();
            comboBox3 = new ComboBox();
            comboBox4 = new ComboBox();
            comboBox5 = new ComboBox();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            button1 = new Button();
            button2 = new Button();
            label6 = new Label();
            textBox1 = new TextBox();
            button3 = new Button();
            button4 = new Button();
            label7 = new Label();
            groupBox1 = new GroupBox();
            groupBox2 = new GroupBox();
            groupBox3 = new GroupBox();
            groupBox4 = new GroupBox();
            button8 = new Button();
            button7 = new Button();
            label9 = new Label();
            button6 = new Button();
            label8 = new Label();
            button5 = new Button();
            groupBox5 = new GroupBox();
            label15 = new Label();
            label14 = new Label();
            label13 = new Label();
            label12 = new Label();
            label11 = new Label();
            label10 = new Label();
            groupBox1.SuspendLayout();
            groupBox2.SuspendLayout();
            groupBox3.SuspendLayout();
            groupBox4.SuspendLayout();
            groupBox5.SuspendLayout();
            SuspendLayout();
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Location = new Point(151, 26);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(151, 28);
            comboBox1.TabIndex = 0;
            // 
            // comboBox2
            // 
            comboBox2.FormattingEnabled = true;
            comboBox2.Items.AddRange(new object[] { "2400", "4800", "9600" });
            comboBox2.Location = new Point(151, 71);
            comboBox2.Name = "comboBox2";
            comboBox2.Size = new Size(151, 28);
            comboBox2.TabIndex = 1;
            comboBox2.Text = "9600";
            // 
            // comboBox3
            // 
            comboBox3.FormattingEnabled = true;
            comboBox3.Items.AddRange(new object[] { "6", "7", "8" });
            comboBox3.Location = new Point(151, 122);
            comboBox3.Name = "comboBox3";
            comboBox3.Size = new Size(151, 28);
            comboBox3.TabIndex = 2;
            comboBox3.Text = "8";
            // 
            // comboBox4
            // 
            comboBox4.FormattingEnabled = true;
            comboBox4.Items.AddRange(new object[] { "One", "Two" });
            comboBox4.Location = new Point(151, 172);
            comboBox4.Name = "comboBox4";
            comboBox4.Size = new Size(151, 28);
            comboBox4.TabIndex = 3;
            comboBox4.Text = "One";
            // 
            // comboBox5
            // 
            comboBox5.FormattingEnabled = true;
            comboBox5.Items.AddRange(new object[] { "None", "Odd", "Even" });
            comboBox5.Location = new Point(151, 225);
            comboBox5.Name = "comboBox5";
            comboBox5.Size = new Size(151, 28);
            comboBox5.TabIndex = 4;
            comboBox5.Text = "None";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(36, 30);
            label1.Name = "label1";
            label1.Size = new Size(72, 20);
            label1.TabIndex = 5;
            label1.Text = "COM Port";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(36, 75);
            label2.Name = "label2";
            label2.Size = new Size(77, 20);
            label2.TabIndex = 6;
            label2.Text = "Baud Rate";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(36, 126);
            label3.Name = "label3";
            label3.Size = new Size(69, 20);
            label3.TabIndex = 7;
            label3.Text = "Data Bits";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(36, 176);
            label4.Name = "label4";
            label4.Size = new Size(68, 20);
            label4.TabIndex = 8;
            label4.Text = "Stop Bits";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(36, 229);
            label5.Name = "label5";
            label5.Size = new Size(45, 20);
            label5.TabIndex = 9;
            label5.Text = "Parity";
            // 
            // button1
            // 
            button1.Location = new Point(39, 368);
            button1.Name = "button1";
            button1.Size = new Size(114, 38);
            button1.TabIndex = 10;
            button1.Text = "Connect";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // button2
            // 
            button2.Location = new Point(197, 368);
            button2.Name = "button2";
            button2.Size = new Size(117, 38);
            button2.TabIndex = 11;
            button2.Text = "Disconnect";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(127, 336);
            label6.Name = "label6";
            label6.Size = new Size(99, 20);
            label6.TabIndex = 12;
            label6.Text = "Disconnected";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(67, 26);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(187, 27);
            textBox1.TabIndex = 13;
            // 
            // button3
            // 
            button3.Location = new Point(110, 60);
            button3.Name = "button3";
            button3.Size = new Size(113, 32);
            button3.TabIndex = 14;
            button3.Text = "Send";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // button4
            // 
            button4.Location = new Point(107, 272);
            button4.Name = "button4";
            button4.Size = new Size(128, 42);
            button4.TabIndex = 15;
            button4.Text = "Refresh";
            button4.UseVisualStyleBackColor = true;
            button4.Click += button4_Click;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(80, 44);
            label7.Name = "label7";
            label7.Size = new Size(151, 20);
            label7.TabIndex = 16;
            label7.Text = "Waiting for message..";
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(button4);
            groupBox1.Controls.Add(label6);
            groupBox1.Controls.Add(button2);
            groupBox1.Controls.Add(button1);
            groupBox1.Controls.Add(label5);
            groupBox1.Controls.Add(label4);
            groupBox1.Controls.Add(label3);
            groupBox1.Controls.Add(label2);
            groupBox1.Controls.Add(label1);
            groupBox1.Controls.Add(comboBox5);
            groupBox1.Controls.Add(comboBox4);
            groupBox1.Controls.Add(comboBox3);
            groupBox1.Controls.Add(comboBox2);
            groupBox1.Controls.Add(comboBox1);
            groupBox1.Location = new Point(12, 12);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(343, 439);
            groupBox1.TabIndex = 17;
            groupBox1.TabStop = false;
            groupBox1.Text = "Com Port Contol";
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(textBox1);
            groupBox2.Controls.Add(button3);
            groupBox2.Location = new Point(394, 27);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(343, 110);
            groupBox2.TabIndex = 18;
            groupBox2.TabStop = false;
            groupBox2.Text = "Sending to Com";
            // 
            // groupBox3
            // 
            groupBox3.Controls.Add(label7);
            groupBox3.Location = new Point(398, 158);
            groupBox3.Name = "groupBox3";
            groupBox3.Size = new Size(342, 87);
            groupBox3.TabIndex = 19;
            groupBox3.TabStop = false;
            groupBox3.Text = "Received from Com";
            // 
            // groupBox4
            // 
            groupBox4.Controls.Add(button8);
            groupBox4.Controls.Add(button7);
            groupBox4.Controls.Add(label9);
            groupBox4.Controls.Add(button6);
            groupBox4.Controls.Add(label8);
            groupBox4.Controls.Add(button5);
            groupBox4.Location = new Point(394, 265);
            groupBox4.Name = "groupBox4";
            groupBox4.Size = new Size(343, 186);
            groupBox4.TabIndex = 20;
            groupBox4.TabStop = false;
            groupBox4.Text = "Control";
            // 
            // button8
            // 
            button8.Location = new Point(186, 131);
            button8.Name = "button8";
            button8.Size = new Size(105, 40);
            button8.TabIndex = 5;
            button8.Text = "Deactivate";
            button8.UseVisualStyleBackColor = true;
            button8.Click += button8_Click;
            // 
            // button7
            // 
            button7.Location = new Point(51, 131);
            button7.Name = "button7";
            button7.Size = new Size(105, 40);
            button7.TabIndex = 4;
            button7.Text = "Activate";
            button7.UseVisualStyleBackColor = true;
            button7.Click += button7_Click;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Location = new Point(131, 108);
            label9.Name = "label9";
            label9.Size = new Size(90, 20);
            label9.TabIndex = 3;
            label9.Text = "Water Pump";
            // 
            // button6
            // 
            button6.Location = new Point(186, 50);
            button6.Name = "button6";
            button6.Size = new Size(102, 41);
            button6.TabIndex = 2;
            button6.Text = "Close";
            button6.UseVisualStyleBackColor = true;
            button6.Click += button6_Click;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(153, 23);
            label8.Name = "label8";
            label8.Size = new Size(43, 20);
            label8.TabIndex = 1;
            label8.Text = "Door";
            // 
            // button5
            // 
            button5.Location = new Point(51, 50);
            button5.Name = "button5";
            button5.Size = new Size(102, 41);
            button5.TabIndex = 0;
            button5.Text = "Open";
            button5.UseVisualStyleBackColor = true;
            button5.Click += button5_Click;
            // 
            // groupBox5
            // 
            groupBox5.Controls.Add(label15);
            groupBox5.Controls.Add(label14);
            groupBox5.Controls.Add(label13);
            groupBox5.Controls.Add(label12);
            groupBox5.Controls.Add(label11);
            groupBox5.Controls.Add(label10);
            groupBox5.Location = new Point(17, 472);
            groupBox5.Name = "groupBox5";
            groupBox5.Size = new Size(724, 100);
            groupBox5.TabIndex = 21;
            groupBox5.TabStop = false;
            groupBox5.Text = "About The System";
            // 
            // label15
            // 
            label15.AutoSize = true;
            label15.Location = new Point(614, 66);
            label15.Name = "label15";
            label15.Size = new Size(29, 20);
            label15.TabIndex = 5;
            label15.Text = "0%";
            // 
            // label14
            // 
            label14.AutoSize = true;
            label14.Location = new Point(343, 66);
            label14.Name = "label14";
            label14.Size = new Size(26, 20);
            label14.TabIndex = 4;
            label14.Text = "Inf";
            // 
            // label13
            // 
            label13.AutoSize = true;
            label13.Location = new Point(66, 66);
            label13.Name = "label13";
            label13.Size = new Size(38, 20);
            label13.TabIndex = 3;
            label13.Text = "Safe";
            // 
            // label12
            // 
            label12.AutoSize = true;
            label12.Location = new Point(573, 34);
            label12.Name = "label12";
            label12.Size = new Size(112, 20);
            label12.TabIndex = 2;
            label12.Text = "Gas percentage";
            // 
            // label11
            // 
            label11.AutoSize = true;
            label11.Location = new Point(255, 34);
            label11.Name = "label11";
            label11.Size = new Size(233, 20);
            label11.TabIndex = 1;
            label11.Text = "Remaining time to close the Door";
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Location = new Point(66, 34);
            label10.Name = "label10";
            label10.Size = new Size(43, 20);
            label10.TabIndex = 0;
            label10.Text = "State";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(838, 623);
            Controls.Add(groupBox5);
            Controls.Add(groupBox4);
            Controls.Add(groupBox3);
            Controls.Add(groupBox2);
            Controls.Add(groupBox1);
            Name = "Form1";
            Text = "Fire Fighting System";
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            groupBox2.ResumeLayout(false);
            groupBox2.PerformLayout();
            groupBox3.ResumeLayout(false);
            groupBox3.PerformLayout();
            groupBox4.ResumeLayout(false);
            groupBox4.PerformLayout();
            groupBox5.ResumeLayout(false);
            groupBox5.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private ComboBox comboBox1;
        private ComboBox comboBox2;
        private ComboBox comboBox3;
        private ComboBox comboBox4;
        private ComboBox comboBox5;
        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Label label5;
        private Button button1;
        private Button button2;
        private Label label6;
        private TextBox textBox1;
        private Button button3;
        private Button button4;
        private Label label7;
        private GroupBox groupBox1;
        private GroupBox groupBox2;
        private GroupBox groupBox3;
        private GroupBox groupBox4;
        private Button button8;
        private Button button7;
        private Label label9;
        private Button button6;
        private Label label8;
        private Button button5;
        private GroupBox groupBox5;
        private Label label11;
        private Label label10;
        private Label label15;
        private Label label14;
        private Label label13;
        private Label label12;
    }
}
