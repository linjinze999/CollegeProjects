namespace MyPrimeAndSort
{
    partial class PrimeAndSort
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.PrimeOrSort = new System.Windows.Forms.TabControl();
            this.PrimeNumber = new System.Windows.Forms.TabPage();
            this.label2 = new System.Windows.Forms.Label();
            this.IuputYourNumber = new System.Windows.Forms.TextBox();
            this.isPrimeButton = new System.Windows.Forms.Button();
            this.Sort = new System.Windows.Forms.TabPage();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.label1 = new System.Windows.Forms.Label();
            this.ListLength = new System.Windows.Forms.TextBox();
            this.MergeSort = new System.Windows.Forms.Button();
            this.InsertSort = new System.Windows.Forms.Button();
            this.SelectSort = new System.Windows.Forms.Button();
            this.FormList = new System.Windows.Forms.Button();
            this.SortListBox = new System.Windows.Forms.TextBox();
            this.MyListBox = new System.Windows.Forms.TextBox();
            this.Clear = new System.Windows.Forms.Button();
            this.PrimeOrSort.SuspendLayout();
            this.PrimeNumber.SuspendLayout();
            this.Sort.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.SuspendLayout();
            // 
            // PrimeOrSort
            // 
            this.PrimeOrSort.Controls.Add(this.PrimeNumber);
            this.PrimeOrSort.Controls.Add(this.Sort);
            this.PrimeOrSort.Font = new System.Drawing.Font("宋体", 11F);
            this.PrimeOrSort.Location = new System.Drawing.Point(0, 1);
            this.PrimeOrSort.Name = "PrimeOrSort";
            this.PrimeOrSort.SelectedIndex = 0;
            this.PrimeOrSort.Size = new System.Drawing.Size(400, 305);
            this.PrimeOrSort.TabIndex = 0;
            // 
            // PrimeNumber
            // 
            this.PrimeNumber.BackColor = System.Drawing.Color.Transparent;
            this.PrimeNumber.Controls.Add(this.label2);
            this.PrimeNumber.Controls.Add(this.IuputYourNumber);
            this.PrimeNumber.Controls.Add(this.isPrimeButton);
            this.PrimeNumber.Location = new System.Drawing.Point(4, 25);
            this.PrimeNumber.Name = "PrimeNumber";
            this.PrimeNumber.Padding = new System.Windows.Forms.Padding(3);
            this.PrimeNumber.Size = new System.Drawing.Size(392, 271);
            this.PrimeNumber.TabIndex = 0;
            this.PrimeNumber.Text = "素数判断";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("宋体", 18F);
            this.label2.Location = new System.Drawing.Point(64, 56);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(286, 24);
            this.label2.TabIndex = 2;
            this.label2.Text = "请输入一个大于0的整数：";
            // 
            // IuputYourNumber
            // 
            this.IuputYourNumber.BackColor = System.Drawing.SystemColors.Info;
            this.IuputYourNumber.Font = new System.Drawing.Font("宋体", 15F);
            this.IuputYourNumber.Location = new System.Drawing.Point(111, 119);
            this.IuputYourNumber.Name = "IuputYourNumber";
            this.IuputYourNumber.Size = new System.Drawing.Size(168, 30);
            this.IuputYourNumber.TabIndex = 1;
            // 
            // isPrimeButton
            // 
            this.isPrimeButton.Font = new System.Drawing.Font("宋体", 15F);
            this.isPrimeButton.Location = new System.Drawing.Point(127, 179);
            this.isPrimeButton.Name = "isPrimeButton";
            this.isPrimeButton.Size = new System.Drawing.Size(140, 30);
            this.isPrimeButton.TabIndex = 0;
            this.isPrimeButton.Text = "判断是否素数";
            this.isPrimeButton.UseVisualStyleBackColor = true;
            this.isPrimeButton.Click += new System.EventHandler(this.isPrimeButton_Click);
            // 
            // Sort
            // 
            this.Sort.BackColor = System.Drawing.Color.Transparent;
            this.Sort.Controls.Add(this.splitContainer1);
            this.Sort.Font = new System.Drawing.Font("宋体", 12F);
            this.Sort.Location = new System.Drawing.Point(4, 25);
            this.Sort.Name = "Sort";
            this.Sort.Padding = new System.Windows.Forms.Padding(3);
            this.Sort.Size = new System.Drawing.Size(392, 276);
            this.Sort.TabIndex = 1;
            this.Sort.Text = "排序";
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(3, 3);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.Clear);
            this.splitContainer1.Panel1.Controls.Add(this.label1);
            this.splitContainer1.Panel1.Controls.Add(this.ListLength);
            this.splitContainer1.Panel1.Controls.Add(this.MergeSort);
            this.splitContainer1.Panel1.Controls.Add(this.InsertSort);
            this.splitContainer1.Panel1.Controls.Add(this.SelectSort);
            this.splitContainer1.Panel1.Controls.Add(this.FormList);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.SortListBox);
            this.splitContainer1.Panel2.Controls.Add(this.MyListBox);
            this.splitContainer1.Size = new System.Drawing.Size(386, 270);
            this.splitContainer1.SplitterDistance = 114;
            this.splitContainer1.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Verdana", 12F);
            this.label1.Location = new System.Drawing.Point(2, 14);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(111, 18);
            this.label1.TabIndex = 5;
            this.label1.Text = "输入数组大小:";
            // 
            // ListLength
            // 
            this.ListLength.BackColor = System.Drawing.SystemColors.Info;
            this.ListLength.Font = new System.Drawing.Font("宋体", 10F);
            this.ListLength.Location = new System.Drawing.Point(5, 43);
            this.ListLength.Name = "ListLength";
            this.ListLength.Size = new System.Drawing.Size(106, 23);
            this.ListLength.TabIndex = 4;
            // 
            // MergeSort
            // 
            this.MergeSort.Font = new System.Drawing.Font("Verdana", 11F);
            this.MergeSort.Location = new System.Drawing.Point(5, 208);
            this.MergeSort.Name = "MergeSort";
            this.MergeSort.Size = new System.Drawing.Size(106, 25);
            this.MergeSort.TabIndex = 3;
            this.MergeSort.Text = "归并排序";
            this.MergeSort.UseVisualStyleBackColor = true;
            this.MergeSort.Click += new System.EventHandler(this.MergeSort_Click);
            // 
            // InsertSort
            // 
            this.InsertSort.Font = new System.Drawing.Font("Verdana", 11F);
            this.InsertSort.Location = new System.Drawing.Point(5, 177);
            this.InsertSort.Name = "InsertSort";
            this.InsertSort.Size = new System.Drawing.Size(106, 25);
            this.InsertSort.TabIndex = 2;
            this.InsertSort.Text = "插入排序";
            this.InsertSort.UseVisualStyleBackColor = true;
            this.InsertSort.Click += new System.EventHandler(this.InsertSort_Click);
            // 
            // SelectSort
            // 
            this.SelectSort.Font = new System.Drawing.Font("Verdana", 11F);
            this.SelectSort.Location = new System.Drawing.Point(5, 146);
            this.SelectSort.Name = "SelectSort";
            this.SelectSort.Size = new System.Drawing.Size(106, 25);
            this.SelectSort.TabIndex = 1;
            this.SelectSort.Text = "选择排序";
            this.SelectSort.UseVisualStyleBackColor = true;
            this.SelectSort.Click += new System.EventHandler(this.SelectSort_Click);
            // 
            // FormList
            // 
            this.FormList.Font = new System.Drawing.Font("Verdana", 11F);
            this.FormList.Location = new System.Drawing.Point(5, 75);
            this.FormList.Name = "FormList";
            this.FormList.Size = new System.Drawing.Size(106, 25);
            this.FormList.TabIndex = 0;
            this.FormList.Text = "生成数组";
            this.FormList.UseVisualStyleBackColor = true;
            this.FormList.Click += new System.EventHandler(this.FormList_Click);
            // 
            // SortListBox
            // 
            this.SortListBox.BackColor = System.Drawing.SystemColors.ControlLight;
            this.SortListBox.Location = new System.Drawing.Point(3, 146);
            this.SortListBox.Multiline = true;
            this.SortListBox.Name = "SortListBox";
            this.SortListBox.ReadOnly = true;
            this.SortListBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.SortListBox.Size = new System.Drawing.Size(262, 119);
            this.SortListBox.TabIndex = 1;
            // 
            // MyListBox
            // 
            this.MyListBox.BackColor = System.Drawing.SystemColors.ControlLight;
            this.MyListBox.Location = new System.Drawing.Point(3, 3);
            this.MyListBox.Multiline = true;
            this.MyListBox.Name = "MyListBox";
            this.MyListBox.ReadOnly = true;
            this.MyListBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.MyListBox.Size = new System.Drawing.Size(262, 117);
            this.MyListBox.TabIndex = 0;
            // 
            // Clear
            // 
            this.Clear.Font = new System.Drawing.Font("Verdana", 11F);
            this.Clear.Location = new System.Drawing.Point(5, 239);
            this.Clear.Name = "Clear";
            this.Clear.Size = new System.Drawing.Size(106, 25);
            this.Clear.TabIndex = 6;
            this.Clear.Text = "清空";
            this.Clear.UseVisualStyleBackColor = true;
            this.Clear.Click += new System.EventHandler(this.Clear_Click);
            // 
            // PrimeAndSort
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.MenuBar;
            this.ClientSize = new System.Drawing.Size(399, 312);
            this.Controls.Add(this.PrimeOrSort);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(415, 350);
            this.MinimumSize = new System.Drawing.Size(415, 350);
            this.Name = "PrimeAndSort";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "PrimeAndSort";
            this.Load += new System.EventHandler(this.PrimeAndSort_Load);
            this.PrimeOrSort.ResumeLayout(false);
            this.PrimeNumber.ResumeLayout(false);
            this.PrimeNumber.PerformLayout();
            this.Sort.ResumeLayout(false);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.PerformLayout();
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl PrimeOrSort;
        private System.Windows.Forms.TabPage PrimeNumber;
        private System.Windows.Forms.TextBox IuputYourNumber;
        private System.Windows.Forms.Button isPrimeButton;
        private System.Windows.Forms.TabPage Sort;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.Button InsertSort;
        private System.Windows.Forms.Button SelectSort;
        private System.Windows.Forms.Button FormList;
        private System.Windows.Forms.Button MergeSort;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox ListLength;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox SortListBox;
        private System.Windows.Forms.TextBox MyListBox;
        private System.Windows.Forms.Button Clear;

    }
}

