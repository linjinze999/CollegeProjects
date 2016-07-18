using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using PrimeAndSort;

namespace MyPrimeAndSort
{
    public partial class PrimeAndSort : Form
    {
        public PrimeAndSort()
        {
            InitializeComponent();
        }

        private void PrimeAndSort_Load(object sender, EventArgs e)
        {

        }

        private int[] MyArray;
        private int length=0;
        private ClassPAS pas = new ClassPAS();

        private void isPrimeButton_Click(object sender, EventArgs e)//素数判断按钮
        {
            int result=pas.isPrimeNumber(IuputYourNumber.Text);
            if (result == -3)//输入字符串不是整数
                MessageBox.Show("请输入正确的整数格式！","素数判断");
            else if (result == -2)//输入整数不大于0
                MessageBox.Show("整数值应大于0！", "素数判断");
            else if (result == -1)//输入整数大于1000
                MessageBox.Show("整数值应小于1000！", "素数判断");
            else if (result==0)
                MessageBox.Show(IuputYourNumber.Text + "不是素数！", "素数判断");
            else
                MessageBox.Show(IuputYourNumber.Text + "是素数！", "素数判断");
        }

        private void FormList_Click(object sender, EventArgs e)//生成列表按钮
        {
            if (int.TryParse(ListLength.Text, out length))//字符串格式正确
            {
                if (length > 0) //列表大小大于0
                { 
                    int[] MyList=new int[length];
                    
                    pas.FormList(MyList,length);
                    MyArray = MyList;
                    String allList="";
                    for (int i = 0; i < length; i++)
                        allList += MyList[i] + ",";
                    MyListBox.Text = allList;
                }
                else//列表大小小于等于0
                    MessageBox.Show("数组大小应大于0", "数组大小");
            }
            else//字符串格式错误
                MessageBox.Show("请输入一个整数！", "数组大小");

        }

        private void SelectSort_Click(object sender, EventArgs e)
        {
            if(length>0)
            {
                SortListBox.Text = "";
                int[] SortArray;
                SortArray = MyArray;
                pas.SelectionSort(SortArray,length);
                String allList = "";
                for (int i = 0; i < length; i++)
                    allList += SortArray[i] + ",";
                SortListBox.Text = allList;
            }
            else
                MessageBox.Show("未查找到数组！", "选择排序");
            
        }

        private void InsertSort_Click(object sender, EventArgs e)
        {
            if (length > 0)
            {
                SortListBox.Text = "";
                int[] SortArray;
                SortArray = MyArray;
                pas.InsertionSort(SortArray, length);
                String allList = "";
                for (int i = 0; i < length; i++)
                    allList += SortArray[i] + ",";
                SortListBox.Text = allList;
            }
            else
                MessageBox.Show("未查找到数组！", "插入排序");
        }

        private void MergeSort_Click(object sender, EventArgs e)
        {
            if (length > 0)
            {
                SortListBox.Text = "";
                int[] SortArray;
                SortArray = MyArray;
                pas.MergeSort(SortArray, 0, length-1);
                String allList = "";
                for (int i = 0; i < length; i++)
                    allList += SortArray[i] + ",";
                SortListBox.Text = allList;
            }
            else
                MessageBox.Show("未查找到数组！", "归并排序");
        }

        private void Clear_Click(object sender, EventArgs e)
        {
            SortListBox.Text = "";
        }



    }
}
