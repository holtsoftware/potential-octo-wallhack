using Sannel;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace MetaDataFixer
{
	class Program
	{
		public static Regex seasonShowRegex = new Regex(
	  "(?<Season>[0-9]{1,3})_(?<Episode>[0-9]{1,3}) (?<Title>.*).(m"+
	  "4v|mp4)",
	RegexOptions.CultureInvariant
	| RegexOptions.Compiled
	);
		static void Main(string[] aStrings)
		{
			var args = new Arguments(aStrings);
			StringBuilder globalArgs = new StringBuilder();

			if(!args.HasArgument("showname"))
			{
				throw new ArgumentException("--showname is required.");
			}
			globalArgs.AppendFormat(" --TVShowName \"{0}\"", args.ArgumentValue("showname"));

			if(args.NonArgumentValues.Count <= 0)
			{
				throw new ArgumentException("You must provide the destination directory.");
			}

			Console.WriteLine("Destination: {0}", args.NonArgumentValues[0]);
			DirectoryInfo destination = new DirectoryInfo(args.NonArgumentValues[0]);
			if(!destination.Exists)
			{
				destination.Create();
			}

			DirectoryInfo di = new DirectoryInfo(Environment.CurrentDirectory);

			foreach(var file in di.GetFiles("*.m??"))
			{
				var firstMatch = seasonShowRegex.Match(file.Name);
				if(firstMatch.Success)
				{
					var season = int.Parse(firstMatch.Groups["Season"].Value);
					var episode = int.Parse(firstMatch.Groups["Episode"].Value);
					String title = firstMatch.Groups["Title"].Value;
					if(title.Contains('_'))
					{
						String line = null;
						do
						{
							Console.WriteLine("Please enter the corrected title: {0}", title);
						}
						while (String.IsNullOrWhiteSpace(line = Console.ReadLine()));
						title = line;
					}

					String fileName = title;
					foreach(var v in Path.GetInvalidFileNameChars())
					{
						while (fileName.Contains(v))
						{
							fileName = fileName.Replace(v, '_');
						}
					}

					ProcessFile(file, String.Format("{0} --title \"{2:00} {1}\"",globalArgs.ToString(), title, episode), Path.Combine(destination.FullName, String.Format("{0} - s{1:00}e{2:00} - {3}.mp4", args.ArgumentValue("showname"), season, episode, fileName)));
				}
				else
				{
					ProcessFile(file, globalArgs.ToString(), Path.ChangeExtension(Path.Combine(destination.FullName, file.Name), ".mp4"));
				}
			}
		}

		static void ProcessFile(FileInfo fi, String extraArgs, String destination)
		{
			ProcessStartInfo spi = new ProcessStartInfo("AtomicParsley");
			spi.Arguments = String.Format("\"{0}\" -o \"{1}\" {2}", fi.FullName, destination, extraArgs);
			Console.WriteLine("Argument: {0}", spi.Arguments);

			var run = Process.Start(spi);
			run.WaitForExit();
		}
	}
}
