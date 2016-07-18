using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PrimeAndSort
{
    public class ClassPAS
    {

        /*------------------素数判断-------------------*/
        public int isPrimeNumber(String number)
        {
            int num;
            if (!(int.TryParse(number, out num)))//字符串格式错误
                return -3;
            if (num <= 0)//该整数小于等于0
                return -2;
            if (num > 1000)//该整数大于1000
                return -1;
            if (num == 2 || num == 3 || num == 5) //素数
                return 1;
            if (num == 1 || num % 2 == 0 || num % 3 == 0 || num % 5 == 0) //非素数
                return 0;

            long c = 7;
            int maxc = (int)Math.Sqrt(num);
            int[] addNum = { 4, 2, 4, 2, 4, 6, 2, 6 };
            while (c <= maxc)
            {
                for (int i = 0; i < 8; i++)
                {
                    if (num % c == 0)
                        return 0;
                    c += addNum[i];
                }
            }

            return 1;

        }/*------------------素数判断-------------------*/



        /*------------------随机数组生成-------------------*/
        public void FormList(int[] MyList, int length)
        {
            Random rd = new Random((int)DateTime.Now.Ticks);
            for (int i = 0; i < length; i++)
                MyList[i] = rd.Next(1000);
        }/*------------------随机数组生成-------------------*/



        /*------------------选择排序-------------------*/
        public void SelectionSort(int[] DataArray, int length)
        {
            for (int i = 0; i < length - 1; i++)    //从第一个位置开始  
            {
                int index = i;
                for (int j = i + 1; j < length; j++)    //寻找最小的数据索引   
                    if (DataArray[j] < DataArray[index])
                        index = j;

                if (index != i)    //如果最小数位置变化则交换  
                {
                    int temp = DataArray[index];
                    DataArray[index] = DataArray[i];
                    DataArray[i] = temp;
                }
            }
        }/*------------------选择排序-------------------*/
        


        /*------------------插入排序-------------------*/
        public void InsertionSort(int[] DataArray, int length)
        {
            for (int i = 1; i < length; i++)
            {
                if (DataArray[i - 1] > DataArray[i])
                {
                    int temp = DataArray[i];
                    int j = i;
                    while (j > 0 && DataArray[j - 1] > temp)
                    {
                        DataArray[j] = DataArray[j - 1];
                        j--;
                    }
                    DataArray[j] = temp;
                }
            }
        }/*------------------插入排序-------------------*/



        /*------------------归并排序-------------------*/
        void merge(int[] data, int p, int q, int r)//归并排序：合并数组  
        {
            int n1, n2, i, j, k;
            int[] left, right;

            n1 = q - p + 1;
            n2 = r - q;

            left = new int[n1];
            right = new int[n2];

            for (i = 0; i < n1; i++)  //对左数组赋值  
                left[i] = data[p + i];
            for (j = 0; j < n2 ; j++)  //对右数组赋值  
                right[j] = data[q + 1 + j];

            i = j = 0;
            k = p;
            while (i < n1 && j < n2) //将数组元素值两两比较，并合并到data数组  
            {
                if (left[i] <= right[j])
                    data[k++] = left[i++];
                else
                    data[k++] = right[j++];
            }

            for (; i < n1; i++) //如果左数组有元素剩余，则将剩余元素合并到data数组  
                data[k++] = left[i];
            for (; j < n2; j++) //如果右数组有元素剩余，则将剩余元素合并到data数组  
                data[k++] = right[j];
        }

        
        public void MergeSort(int[] data, int p, int r)//归并排序
        {
            int q;
            if (p < r) //只有一个或无记录时不须排序   
            {
                q = (int)((p + r) / 2);      //将data数组分成两半     
                MergeSort(data, p, q);   //递归拆分左数组  
                MergeSort(data, q + 1, r); //递归拆分右数组  
                merge(data, p, q, r);    //合并数组  
            }
        }/*------------------归并排序-------------------*/
    }
}
