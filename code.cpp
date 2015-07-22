using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;
using System.Threading;

/*
Require dependencies
Name:	ChromeDriver
ID:	WebDriver.ChromeDriver.win32
URL:	https://www.nuget.org/packages/WebDriver.ChromeDriver.win32/2.14.0

Name:	Selenium
ID:	Selenium.WebDriver
URL:	https://www.nuget.org/packages/Selenium.WebDriver/2.45.0
*/

/*well I am including over here */
using OpenQA.Selenium;
/* Chrome will do Perfect Job so adding it. :) */
using OpenQA.Selenium.Chrome;
/* Some File Writing */
using System.IO;
/* Xpath Lib */
using System.Xml.XPath;


/*
Project Home URL: http://www.naukrigulf.com/
Project Prececc URL: http://www.naukrigulf.com/jobs-in-uae-4?fa=3
*/


namespace NaukriGulf.Com
{
    public partial class NaukriGulf_Form : Form
    {
        //user desktop path to store display files
        string path_Desktop = Environment.GetFolderPath(Environment.SpecialFolder.Desktop);
        public string job_region_selected = "United Arab Emirates";
        public Int32 job_type_Selection = 016;
        public string job_type_selected = "IT Software";
        //how many Pages ? n=1
        public Int32 current_number_jobs = 0;   //total number of current jobs processed
        public Int32 int_main_pages_total_jobs_count = 0;   //total number of jobs of Specific Type
        public Int32 int_main_pages_count = 0;  // total number of pagess
        string defautl_Url = "http://www.naukrigulf.com";
        //double progress = (x / max) * 100;

        private void NaukriGulf_Function(string defautl_Url)
        {

            /* initializing chrome driver */
            var chrome_Driver = ChromeDriverService.CreateDefaultService();
            //no need to show disturbing command window so set it hidden
            chrome_Driver.HideCommandPromptWindow = true;

            chrome_Driver.Start();
            //initialize chrome driver 
            var main_page_chrome_Driver_Obj = new ChromeDriver(chrome_Driver, new ChromeOptions());

            /* create a csv file for output*/
            try
            {
                File.WriteAllText(Path.Combine(path_Desktop, "NaukriGulf_Scrapped_DataSet_" + job_region_selected + "_" + job_type_selected + ".csv"), "Job Title, Company, Description, Location, Experience,  Keyskills, Region, Industry, Date\r\n");
            }
            catch (Exception ex)
            {

                //incase of file is open or readonly or no permission show message
                result_richTextBox.AppendText(ex.StackTrace);
                MessageBox.Show("Cannot write to file !");
            }


            int totalPages_Int = 1;
            do
            {
                main_page_chrome_Driver_Obj.Navigate().GoToUrl(defautl_Url + "/jobs-in-uae-" + totalPages_Int + "?fa=" + job_type_Selection);   //job_type_Selection = 016; totalPages_Int = 0;
                // var job_functional_area = main_page_chrome_Driver_Obj.FindElementsByXPath("//*[@id='fareaContainer']/div/a");
                var main_page_dom = main_page_chrome_Driver_Obj.FindElementsByXPath("//*[@id='resultsData']");
                if (totalPages_Int != 1)
                {
                    //skip Pages Counting in rest of loop
                }
                else
                {
                    // only count total number pages once at page one
                    var main_pages_count = main_page_dom[0].FindElement(By.XPath(".//div[1]/div[2]/strong[2]")).Text;
                    //wola ! I need only digits, but it has " 15302 Advertisements ", extract only digits
                    var str_main_pages_count = Regex.Match(main_pages_count, @"\d+").Value;
                    //It needs to be converted to iNT
                    int_main_pages_total_jobs_count = Int32.Parse(str_main_pages_count);
                    int_main_pages_count = (int)Math.Ceiling((double)int_main_pages_total_jobs_count / (double)25);
                }

                var main_page_jobs = main_page_chrome_Driver_Obj.FindElementsByXPath("//*[@class='artical']");      //25 jobs per page

                //+++++++++++++++++++++++++ 25 Jobs Loop in Single Main Page starts ++++++++++++++++++++++++
                current_number_jobs = current_number_jobs + (int)(main_page_jobs.Count());
                for (int job_index = 0; job_index < main_page_jobs.Count(); job_index++)
                {
                    // declare Initialize all variables to nothing
                    var job_title = "";
                    var job_company = "";
                    var job_desc = "";

                    var job_location = "";
                    var job_region = "";

                    //var job_nationality = "";
                    var job_experience = "";
                    var job_keyskils = "";
                    // var job_function = "";
                    //var job_role = "";
                    var job_industry = job_type_selected;
                    var job_date = "";
                    //var job_ref_code = "";

                    //+++++++++++++ values Scraper Region +++++++++++++++++++++++++

                    job_title = main_page_jobs[job_index].FindElement(By.XPath("./div[@class='aCont']/div/a/span[1]")).Text;
                    job_company = main_page_jobs[job_index].FindElement(By.XPath("./div[@class='aCont']/div/a/span[2]")).Text;
                    job_desc = main_page_jobs[job_index].FindElement(By.XPath("./div[@class='aCont']/a/p")).Text;

                    job_location = main_page_jobs[job_index].FindElement(By.XPath("./div[@class='aCont']/div/p/span[2]")).Text;
                    string input_job_location = job_location;
                    string[] values_job_location = input_job_location.Split('-'); //Abu Dhabi - United Arab Emirates
                    job_region = values_job_location.Last(); // United Arab Emirates

                    job_experience = main_page_jobs[job_index].FindElement(By.XPath("./div[@class='aCont']/div/p/span[1]")).Text;
                    try
                    {
                        string input_job_keyskils = main_page_jobs[job_index].FindElement(By.XPath("./div[@class='aCont']/a/span")).Text;
                        string[] values_job_keyskils = input_job_keyskils.Split(':'); //Keywords: sharepoint, MOSS, .Net, ms sql
                        job_keyskils = values_job_keyskils.Last(); //sharepoint, MOSS, .Net, ms sql
                    }
                    catch (Exception ex)
                    {
                        job_keyskils = "NULL";
                        result_richTextBox.AppendText(ex.StackTrace);
                        //continue;
                    }
                    var job_date_before_conversion = main_page_jobs[job_index].FindElement(By.XPath(".//div[2]/span/span[1]")).Text;
                    job_date = timeStampCnversion(job_date_before_conversion + " 2015");
                    //+++++++++++++ values Scraper Region ENd +++++++++++++++++++++++++

                    //Dispaly Output and write data to CSV file
                    //Job Title, Company, Description, Location, Experience,  Keyskills, Region, Industry, Date\r\n
                    result_richTextBox.AppendText("\nJob Title: " + job_title.ToString().Trim() + "\nCompany: " + job_company.ToString().Trim() + "\nDescription: " + job_desc.ToString().Trim() + "\nLocation: " + job_location.ToString().Trim() + "\nExperience: " + job_experience.ToString().Trim() + "\nKeyskills: " + job_keyskils.ToString().Trim() + "\nRegion: " + job_region.ToString().Trim() + "\nIndustry: " + job_industry.ToString().Trim() + "\nDate: " + job_date.ToString().Trim() + "\r.....................................................................................................\n");
                    File.AppendAllText(Path.Combine(path_Desktop, "NaukriGulf_Scrapped_DataSet_" + job_region_selected + "_" + job_type_selected + ".csv"), job_title.ToString().Trim().Replace(",", "") + "," + job_company.ToString().Trim().Replace(",", "") + "," + job_desc.ToString().Trim().Replace(",", "") + "," + job_location.ToString().Trim().Replace(",", "") + "," + job_experience.ToString().Trim().Replace(",", "") + "," + job_keyskils.ToString().Trim().Replace(",", "") + "," + job_region.ToString().Trim().Replace(",", "") + "," + job_industry.ToString().Trim().Replace(",", "") + "," + job_date.ToString().Trim().Replace(",", "") + "\r\n");

                    //show progress/status
                    this.job_number_status_label.Text = current_number_jobs.ToString() + "/" + int_main_pages_total_jobs_count.ToString();
                    this.result_richTextBox.AppendText("\r\n" + job_title + "\t\t");

                }   //End Sub Page Loop

                this.job_pages_status_label.Text = totalPages_Int + "/" + int_main_pages_count;
                this.scraper_progressbar_label.Visible = true;
                this.scraper_progressBar.Visible = true;
                scraper_progressBar.Value = totalPages_Int * scraper_progressBar.Maximum / int_main_pages_count;
                Application.DoEvents();
                if (scraper_progressBar.Value != 100)
                {
                    scraper_progressbar_label.Text = string.Format("{0}% Completed", scraper_progressBar.Value);
                }
                else { scraper_progressbar_label.Text = "Finished!"; }
                totalPages_Int++;
            } while (totalPages_Int <= int_main_pages_count);//End Main Page Loop

            //dispose all the data associated with chromedriver
            main_page_chrome_Driver_Obj.Dispose();
            //Quit chrome driver
            main_page_chrome_Driver_Obj.Quit();


        } //end NaukriGulf_Function
        public NaukriGulf_Form()
        {
            InitializeComponent();
        }

        private void start_btn_Click(object sender, EventArgs e)
        {
            scraper_progressBar.Value = 0;
            scraper_progressbar_label.Text = "Progress";
            NaukriGulf_Function(defautl_Url);
        }

        private void job_type_comboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            ComboBox cmb = (ComboBox)sender;
            int selectedIndex = cmb.SelectedIndex;
            switch (selectedIndex)
            {
                /*Job Types Selectors with values*/

                case 0: job_type_selected = "Engineering"; job_type_Selection = 038; break;
                case 1: job_type_selected = "Sales - Business Development"; job_type_Selection = 026; break;
                case 2: job_type_selected = "Accounts - Taxation - Audit - Company Secretary"; job_type_Selection = 01; break;
                case 3: job_type_selected = "Administration"; job_type_Selection = 034; break;
                case 4: job_type_selected = "IT Software"; job_type_Selection = 016; break;
                case 5: job_type_selected = "Finance - Treasury"; job_type_Selection = 04; break;
                case 6: job_type_selected = "Advertising - Media Planning - PR"; job_type_Selection = 02; break;
                case 7: job_type_selected = "Architecture - Interior Design"; job_type_Selection = 03; break;
                case 8: job_type_selected = "Buying - Purchase - Procurement - Vendor Management"; job_type_Selection = 042; break;
                case 9: job_type_selected = "Cabin Crew - Flight Attendant - Steward - Air Hostess"; job_type_Selection = 043; break;
                case 10: job_type_selected = "Cashier - Teller - Billing &amp; Payment"; job_type_Selection = 044; break;
                case 11: job_type_selected = "Chefs - F&amp;B - Housekeeping - Front Desk"; job_type_Selection = 011; break;
                case 12: job_type_selected = "Contract Management - Estimation - Tendering - Quantity Surveying"; job_type_Selection = 046; break;
                case 13: job_type_selected = "Corporate Planning - Consulting - Strategy - M&amp;A"; job_type_Selection = 05; break;
                case 14: job_type_selected = "Data Entry - Operations - Back Office Processing"; job_type_Selection = 035; break;
                case 15: job_type_selected = "DBA - Datawarehousing (IT Software)"; job_type_Selection = 047; break;
                case 16: job_type_selected = "Doctor - Nurse - Paramedics - Hospital Technicians - Medical Research"; job_type_Selection = 020; break;
                case 17: job_type_selected = "Drilling"; job_type_Selection = 049; break;
                case 18: job_type_selected = "Equipment Operations - Machine - Crane - Forklift"; job_type_Selection = 039; break;
                case 19: job_type_selected = "ERP - CRM (IT Software)"; job_type_Selection = 050; break;
                case 20: job_type_selected = "Flight Operations (Pilots - Technical Staff - Ground Staff)"; job_type_Selection = 051; break;
                case 21: job_type_selected = "Fresh Graduates - Management Trainee - Intern - No Experience"; job_type_Selection = 07; break;
                case 22: job_type_selected = "Geotechnical - Geologists - Petrophysicist"; job_type_Selection = 052; break;
                case 23: job_type_selected = "Graphic Design - Web Design - Art - Visualiser"; job_type_Selection = 09; break;
                case 24: job_type_selected = "Guards - Security Services"; job_type_Selection = 010; break;
                case 25: job_type_selected = "Helpdesk - Customer Service - Telecalling"; job_type_Selection = 06; break;
                case 26: job_type_selected = "HR - Human Relations - Industrial Relations"; job_type_Selection = 012; break;
                case 27: job_type_selected = "HSE (Health - Safety - Environment)"; job_type_Selection = 053; break;
                case 28: job_type_selected = "Installation - Maintenance - Operations - Repair"; job_type_Selection = 037; break;
                case 29: job_type_selected = "Insurance - Underwriting - Surveying - Actuary"; job_type_Selection = 013; break;
                case 30: job_type_selected = "IT Hardware Support - IT Hardware Repair &amp; Maintenance"; job_type_Selection = 015; break;
                case 31: job_type_selected = "Journalism - Content Writing - Editing - Correspondent"; job_type_Selection = 017; break;
                case 32: job_type_selected = "Language Translation"; job_type_Selection = 054; break;
                case 33: job_type_selected = "Lawyers - Legal Advisors"; job_type_Selection = 018; break;
                case 34: job_type_selected = "Logistics - Supply Chain"; job_type_Selection = 023; break;
                case 35: job_type_selected = "Marine Services (Marine Officer - Marine Engineer - Ship Chandler - Diver)"; job_type_Selection = 041; break;
                case 36: job_type_selected = "Marketing - Brand Management - Marketing Research - Digital Marketing"; job_type_Selection = 019; break;
                case 37: job_type_selected = "MEP (Mechanical - Electrical - Plumbing)"; job_type_Selection = 055; break;
                case 38: job_type_selected = "Merchandising &amp; Planning - Category Management"; job_type_Selection = 08; break;
                case 39: job_type_selected = "Other"; job_type_Selection = 01000; break;
                case 40: job_type_selected = "Product Development - Product Management"; job_type_Selection = 056; break;
                case 41: job_type_selected = "Production - Manufacturing"; job_type_Selection = 022; break;
                case 42: job_type_selected = "Quality - Testing - QA - QC - Inspector"; job_type_Selection = 036; break;
                case 43: job_type_selected = "R&amp;D - Research &amp; Development"; job_type_Selection = 024; break;
                case 44: job_type_selected = "Secretary - Front Office - Personal Assistant (PA)"; job_type_Selection = 027; break;
                case 45: job_type_selected = "Shop Drawing - Drafting - Draughtsman"; job_type_Selection = 057; break;
                case 46: job_type_selected = "Site Engineering - Projects"; job_type_Selection = 028; break;
                case 47: job_type_selected = "Software Development - Application Development (IT Software)"; job_type_Selection = 058; break;
                case 48: job_type_selected = "Store Operations (for retail industry)"; job_type_Selection = 059; break;
                case 49: job_type_selected = "Surveying (Civil)"; job_type_Selection = 060; break;
                case 50: job_type_selected = "System Administration - Network Administration - Security (IT Software)"; job_type_Selection = 061; break;
                case 51: job_type_selected = "Teaching - Education"; job_type_Selection = 029; break;
                case 52: job_type_selected = "Telecom Engineering - Communications Engineering"; job_type_Selection = 040; break;
                case 53: job_type_selected = "Ticketing - Reservations"; job_type_Selection = 030; break;
                case 54: job_type_selected = "Top Management - Senior Management"; job_type_Selection = 031; break;
                case 55: job_type_selected = "Training - Learning"; job_type_Selection = 062; break;
                case 56: job_type_selected = "Transport - Driving"; job_type_Selection = 063; break;
                case 57: job_type_selected = "TV Anchors - Reporters - Film Production - RJ - VJ"; job_type_Selection = 032; break;
                case 58: job_type_selected = "Visual Merchandizing"; job_type_Selection = 064; break;
            }// End Switch
            //result_richTextBox.AppendText("\r\n" + job_type_selected+"=> "+job_type_Selection.ToString());
        }// End ComboBox Job Type Selector


        //Date to Time Stamp Converter Function
        public string timeStampCnversion(string string_date)
        {
            //standard date timeStampCnversion format is 6/14/2015
            // current website date format is 16th Apr 2015
            string s = string_date;
            string[] values = s.Split(' ');
            string str_day = values[0].Trim();
            string str_month = values[1].Trim();
            string str_year = values[2].Trim();

            int int_day = 0;
            int int_month = 0;
            int int_year = int.Parse(str_year);

            string[] numbers = Regex.Split(str_day, @"\D+");
            foreach (string value in numbers)
            {
                if (!string.IsNullOrEmpty(value))
                {
                    int_day = int.Parse(value);
                }
            }

            switch (str_month)
            {
                case "Jan":
                    int_month = 1;
                    break;
                case "Feb":
                    int_month = 2;
                    break;
                case "Mar":
                    int_month = 3;
                    break;
                case "Apr":
                    int_month = 4;
                    break;
                case "May":
                    int_month = 5;
                    break;
                case "Jun":
                    int_month = 6;
                    break;
                case "Jul":
                    int_month = 7;
                    break;
                case "Aug":
                    int_month = 8;
                    break;
                case "Sep":
                    int_month = 9;
                    break;
                case "Oct":
                    int_month = 10;
                    break;
                case "Nov":
                    int_month = 11;
                    break;
                case "Dec":
                    int_month = 12;
                    break;

            }//end switch

            DateTime date = new DateTime(int_year, int_month, int_day, 12, 0, 0, 0);
            DateTime epoch = new DateTime(1970, 1, 1, 0, 0, 0, 0);
            TimeSpan span = (date - epoch);
            double unixTime = span.TotalSeconds;
            return unixTime.ToString();
        }

        private void result_richTextBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void quit_btn_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Really Quit?", "Confirm quit", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                this.Close();
            }
        }

        private void open_btn_Click(object sender, EventArgs e)
        {
            Process.Start(path_Desktop);
        }

        private void job_number_status_label_Click(object sender, EventArgs e)
        {

        }// End Date Time Conversion Function
    }
}