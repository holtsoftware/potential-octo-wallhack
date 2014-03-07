using Sannel.EcoSystem.Engine;
using Sannel.EcoSystem.Interfaces;
using Sannel.EcoSystem.Parts;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Media.Imaging;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

namespace Sannel.EcoSystem.UI
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public sealed partial class MainPage : Page
	{
		private IEcoEngine engine;
		public MainPage()
		{
			this.InitializeComponent();
		}

		protected override void OnNavigatedTo(NavigationEventArgs e)
		{
			base.OnNavigatedTo(e);
			if(engine == null)
			{
				engine = new GroundEngine(25, 25);
				DirtSpawner d = new DirtSpawner();
				d.ImageFile = new Uri("ms-appx:///Assets/Tiles/Dirt.png");
				engine.AddTerrainSpawner(d);
				WaterSpawner w = new WaterSpawner();
				w.ImageFile = new Uri("ms-appx:///Assets/Tiles/Water.png");
				engine.AddTerrainSpawner(w);
				var g = new GrassSpawner();
				g.ImageFile = new Uri("ms-appx:///Assets/Tiles/Grass.png");
				engine.AddTerrainSpawner(g);
				engine.GenerateMap();
				var gridSize = new GridLength(150);
				for(int r=0;r<engine.Rows;r++)
				{
					Tiles.RowDefinitions.Add(new RowDefinition() { Height = gridSize });
				}

				for(int c = 0;c<engine.Columns;c++)
				{
					Tiles.ColumnDefinitions.Add(new ColumnDefinition() { Width = gridSize });
				}

				refreshGrid();
			}
		}

		private void refreshGrid()
		{
			Tiles.Children.Clear();
			for(int r=0;r<engine.Rows;r++)
			{
				for(int c=0;c<engine.Columns;c++)
				{
					var ter = engine.GetTerrainAt(r, c);
					Image img = new Image();
					img.Source = new BitmapImage(ter.ImageFile);
					img.SetValue(Grid.RowProperty, r);
					img.SetValue(Grid.ColumnProperty, c);
					Tiles.Children.Add(img);
				}
			}
		}
	}
}
