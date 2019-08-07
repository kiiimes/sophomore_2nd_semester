﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UnnamedObject
{
    class Program
    {
        class Profile
        {
            public string Name { get; set; }
            public int Height { get; set; }
        }



        static void Main(string[] args)
        {
            Profile[] arrProfile =
        {
            new Profile() {Name = "정우성",Height = 186 },
            new Profile() {Name = "김태희",Height = 158 },
            new Profile() {Name = "고현정",Height = 172 },
            new Profile() {Name = "이문세",Height = 178 },
            new Profile() {Name = "하동훈",Height = 171 }
        };

            var profiles = from h in arrProfile
                           where h.Height > 175
                           orderby h.Height
                           select h.Height * 0.393;
            foreach (var profile in profiles)
            {
                Console.WriteLine(profile);
            }
        }
    }
}
