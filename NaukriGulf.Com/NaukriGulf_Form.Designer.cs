namespace NaukriGulf.Com
{
    partial class NaukriGulf_Form
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
            this.start_btn = new System.Windows.Forms.Button();
            this.result_richTextBox = new System.Windows.Forms.RichTextBox();
            this.job_type_comboBox = new System.Windows.Forms.ComboBox();
            this.url_textBox = new System.Windows.Forms.TextBox();
            this.url_label = new System.Windows.Forms.Label();
            this.open_btn = new System.Windows.Forms.Button();
            this.quit_btn = new System.Windows.Forms.Button();
            this.job_type_label = new System.Windows.Forms.Label();
            this.scraper_progressBar = new System.Windows.Forms.ProgressBar();
            this.scraper_progressbar_label = new System.Windows.Forms.Label();
            this.job_number_label = new System.Windows.Forms.Label();
            this.job_number_status_label = new System.Windows.Forms.Label();
            this.job_pages_label = new System.Windows.Forms.Label();
            this.job_pages_status_label = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // start_btn
            // 
            this.start_btn.Location = new System.Drawing.Point(646, 535);
            this.start_btn.Name = "start_btn";
            this.start_btn.Size = new System.Drawing.Size(75, 23);
            this.start_btn.TabIndex = 0;
            this.start_btn.Text = "&Start";
            this.start_btn.UseVisualStyleBackColor = true;
            this.start_btn.Click += new System.EventHandler(this.start_btn_Click);
            // 
            // result_richTextBox
            // 
            this.result_richTextBox.Location = new System.Drawing.Point(1, 1);
            this.result_richTextBox.Name = "result_richTextBox";
            this.result_richTextBox.Size = new System.Drawing.Size(882, 479);
            this.result_richTextBox.TabIndex = 1;
            this.result_richTextBox.Text = "";
            this.result_richTextBox.TextChanged += new System.EventHandler(this.result_richTextBox_TextChanged);
            // 
            // job_type_comboBox
            // 
            this.job_type_comboBox.FormattingEnabled = true;
            this.job_type_comboBox.Items.AddRange(new object[] {
            "Engineering",
            "Sales / Business Development",
            "Accounts / Taxation / Audit / Company Secretary",
            "Administration",
            "IT Software",
            "Finance / Treasury",
            "Advertising / Media Planning / PR",
            "Architecture / Interior Design",
            "Buying / Purchase / Procurement / Vendor Management",
            "Cabin Crew / Flight Attendant / Steward / Air Hostess",
            "Cashier / Teller / Billing &amp; Payment",
            "Chefs / F&amp;B / Housekeeping / Front Desk",
            "Contract Management / Estimation / Tendering / Quantity Surveying",
            "Corporate Planning / Consulting / Strategy / M&amp;A",
            "Data Entry / Operations / Back Office Processing",
            "DBA / Datawarehousing (IT Software)",
            "Doctor / Nurse / Paramedics / Hospital Technicians / Medical Research",
            "Drilling",
            "Equipment Operations - Machine / Crane / Forklift",
            "ERP / CRM (IT Software)",
            "Flight Operations (Pilots / Technical Staff / Ground Staff)",
            "Fresh Graduates / Management Trainee / Intern / No Experience",
            "Geotechnical / Geologists / Petrophysicist",
            "Graphic Design / Web Design / Art / Visualiser",
            "Guards / Security Services",
            "Helpdesk / Customer Service / Telecalling",
            "HR / Human Relations / Industrial Relations",
            "HSE (Health / Safety / Environment)",
            "Installation / Maintenance / Operations / Repair",
            "Insurance / Underwriting / Surveying / Actuary",
            "IT Hardware Support / IT Hardware Repair &amp; Maintenance",
            "Journalism / Content Writing / Editing / Correspondent",
            "Language Translation",
            "Lawyers / Legal Advisors",
            "Logistics / Supply Chain",
            "Marine Services (Marine Officer / Marine Engineer / Ship Chandler / Diver)",
            "Marketing / Brand Management / Marketing Research / Digital Marketing",
            "MEP (Mechanical / Electrical / Plumbing)",
            "Merchandising &amp; Planning / Category Management",
            "Other",
            "Product Development / Product Management",
            "Production / Manufacturing",
            "Quality / Testing / QA / QC / Inspector",
            "R&amp;D / Research &amp; Development",
            "Secretary / Front Office / Personal Assistant (PA)",
            "Shop Drawing / Drafting / Draughtsman",
            "Site Engineering / Projects",
            "Software Development / Application Development (IT Software)",
            "Store Operations (for retail industry)",
            "Surveying (Civil)",
            "System Administration / Network Administration / Security (IT Software)",
            "Teaching / Education",
            "Telecom Engineering / Communications Engineering",
            "Ticketing / Reservations",
            "Top Management / Senior Management",
            "Training / Learning",
            "Transport / Driving",
            "TV Anchors / Reporters / Film Production / RJ / VJ",
            "Visual Merchandizing"});
            this.job_type_comboBox.Location = new System.Drawing.Point(56, 536);
            this.job_type_comboBox.Name = "job_type_comboBox";
            this.job_type_comboBox.Size = new System.Drawing.Size(584, 21);
            this.job_type_comboBox.TabIndex = 2;
            this.job_type_comboBox.Text = "IT Software";
            this.job_type_comboBox.SelectedIndexChanged += new System.EventHandler(this.job_type_comboBox_SelectedIndexChanged);
            // 
            // url_textBox
            // 
            this.url_textBox.Location = new System.Drawing.Point(30, 513);
            this.url_textBox.Name = "url_textBox";
            this.url_textBox.Size = new System.Drawing.Size(610, 20);
            this.url_textBox.TabIndex = 3;
            this.url_textBox.Text = "http://www.naukrigulf.com";
            // 
            // url_label
            // 
            this.url_label.AutoSize = true;
            this.url_label.Location = new System.Drawing.Point(1, 516);
            this.url_label.Name = "url_label";
            this.url_label.Size = new System.Drawing.Size(23, 13);
            this.url_label.TabIndex = 4;
            this.url_label.Text = "Url:";
            // 
            // open_btn
            // 
            this.open_btn.Location = new System.Drawing.Point(727, 535);
            this.open_btn.Name = "open_btn";
            this.open_btn.Size = new System.Drawing.Size(75, 23);
            this.open_btn.TabIndex = 5;
            this.open_btn.Text = "&Open";
            this.open_btn.UseVisualStyleBackColor = true;
            this.open_btn.Click += new System.EventHandler(this.open_btn_Click);
            // 
            // quit_btn
            // 
            this.quit_btn.Location = new System.Drawing.Point(808, 535);
            this.quit_btn.Name = "quit_btn";
            this.quit_btn.Size = new System.Drawing.Size(75, 23);
            this.quit_btn.TabIndex = 6;
            this.quit_btn.Text = "&Quit";
            this.quit_btn.UseVisualStyleBackColor = true;
            this.quit_btn.Click += new System.EventHandler(this.quit_btn_Click);
            // 
            // job_type_label
            // 
            this.job_type_label.AutoSize = true;
            this.job_type_label.Location = new System.Drawing.Point(0, 540);
            this.job_type_label.Name = "job_type_label";
            this.job_type_label.Size = new System.Drawing.Size(54, 13);
            this.job_type_label.TabIndex = 7;
            this.job_type_label.Text = "Job Type:";
            // 
            // scraper_progressBar
            // 
            this.scraper_progressBar.Location = new System.Drawing.Point(5, 484);
            this.scraper_progressBar.Name = "scraper_progressBar";
            this.scraper_progressBar.Size = new System.Drawing.Size(875, 23);
            this.scraper_progressBar.TabIndex = 8;
            this.scraper_progressBar.Visible = false;
            // 
            // scraper_progressbar_label
            // 
            this.scraper_progressbar_label.AutoSize = true;
            this.scraper_progressbar_label.BackColor = System.Drawing.Color.Transparent;
            this.scraper_progressbar_label.Location = new System.Drawing.Point(795, 489);
            this.scraper_progressbar_label.Name = "scraper_progressbar_label";
            this.scraper_progressbar_label.Size = new System.Drawing.Size(48, 13);
            this.scraper_progressbar_label.TabIndex = 9;
            this.scraper_progressbar_label.Text = "Progress";
            this.scraper_progressbar_label.Visible = false;
            // 
            // job_number_label
            // 
            this.job_number_label.AutoSize = true;
            this.job_number_label.Location = new System.Drawing.Point(683, 516);
            this.job_number_label.Name = "job_number_label";
            this.job_number_label.Size = new System.Drawing.Size(38, 13);
            this.job_number_label.TabIndex = 10;
            this.job_number_label.Text = "Job(s):";
            // 
            // job_number_status_label
            // 
            this.job_number_status_label.AutoSize = true;
            this.job_number_status_label.Location = new System.Drawing.Point(727, 516);
            this.job_number_status_label.Name = "job_number_status_label";
            this.job_number_status_label.Size = new System.Drawing.Size(13, 13);
            this.job_number_status_label.TabIndex = 11;
            this.job_number_status_label.Text = "0";
            this.job_number_status_label.Click += new System.EventHandler(this.job_number_status_label_Click);
            // 
            // job_pages_label
            // 
            this.job_pages_label.AutoSize = true;
            this.job_pages_label.Location = new System.Drawing.Point(795, 516);
            this.job_pages_label.Name = "job_pages_label";
            this.job_pages_label.Size = new System.Drawing.Size(46, 13);
            this.job_pages_label.TabIndex = 12;
            this.job_pages_label.Text = "Page(s):";
            // 
            // job_pages_status_label
            // 
            this.job_pages_status_label.AutoSize = true;
            this.job_pages_status_label.Location = new System.Drawing.Point(847, 516);
            this.job_pages_status_label.Name = "job_pages_status_label";
            this.job_pages_status_label.Size = new System.Drawing.Size(13, 13);
            this.job_pages_status_label.TabIndex = 13;
            this.job_pages_status_label.Text = "0";
            // 
            // NaukriGulf_Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(884, 561);
            this.Controls.Add(this.job_pages_status_label);
            this.Controls.Add(this.job_pages_label);
            this.Controls.Add(this.job_number_status_label);
            this.Controls.Add(this.job_number_label);
            this.Controls.Add(this.scraper_progressbar_label);
            this.Controls.Add(this.scraper_progressBar);
            this.Controls.Add(this.job_type_label);
            this.Controls.Add(this.quit_btn);
            this.Controls.Add(this.open_btn);
            this.Controls.Add(this.url_label);
            this.Controls.Add(this.url_textBox);
            this.Controls.Add(this.job_type_comboBox);
            this.Controls.Add(this.result_richTextBox);
            this.Controls.Add(this.start_btn);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(900, 600);
            this.MinimumSize = new System.Drawing.Size(900, 600);
            this.Name = "NaukriGulf_Form";
            this.Text = "NaukriGulf.Com -Scraper";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button start_btn;
        private System.Windows.Forms.RichTextBox result_richTextBox;
        private System.Windows.Forms.ComboBox job_type_comboBox;
        private System.Windows.Forms.TextBox url_textBox;
        private System.Windows.Forms.Label url_label;
        private System.Windows.Forms.Button open_btn;
        private System.Windows.Forms.Button quit_btn;
        private System.Windows.Forms.Label job_type_label;
        private System.Windows.Forms.ProgressBar scraper_progressBar;
        private System.Windows.Forms.Label scraper_progressbar_label;
        private System.Windows.Forms.Label job_number_label;
        private System.Windows.Forms.Label job_number_status_label;
        private System.Windows.Forms.Label job_pages_label;
        private System.Windows.Forms.Label job_pages_status_label;
    }
}

