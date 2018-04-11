using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace Element
{
    class Node
    {
        public object nodeValue { get; set; }
        public Node next { get; set; }
        public Node prev { get; set; }
    }
}
namespace List
{
    class List<T>
    {
        private Element.Node head;
        private Element.Node tail;
        List()
        {
            head = null; tail = null;
        }
        public void Add(object value)       //Add value at the End of List
        {
            Element.Node newNode = new Element.Node() { nodeValue = value };
            if (head == null && tail == null)   //if It is empty!
            {
                head = newNode;
                tail = newNode;
                return;
            }
            newNode.prev = tail;
            tail.next = newNode;
            tail = newNode;
        }
        public void AddRange(IEnumerable<T> collection)
        {
            foreach (object o in collection)
                Add(o);
        }
        public void Clear()
        {
            while (head != tail)
            {
                Element.Node targetNode = tail;
                tail = tail.prev;
                tail.next = null;
                targetNode.prev = null;
            }
            head = null;
            tail = null;
        }
        public bool Contains(object item)
        {
            Element.Node cur = head;
            while (cur != tail)
            {
                if (cur.nodeValue == item)
                    return true;
            }
            return false;
        }


    }
}
namespace Main
{
    class Program
    {


        static void Main(string[] args)
        {
            List<int> li = new List<int>();
        }
    }
}


