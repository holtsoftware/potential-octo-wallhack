using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sannel.EcoSystem.Base
{
	public struct Precentages
	{
		public uint Min
		{
			get;
			set;
		}

		public uint Max
		{
			get;
			set;
		}

		public byte Water
		{
			get;
			set;
		}

		public byte WaterQuality
		{
			get;
			set;
		}

		public byte MinSize
		{
			get;
			set;
		}

		public byte MaxSize
		{
			get;
			set;
		}

		public GenerationShape GenerationShape
		{
			get;
			set;
		}
	}
}
