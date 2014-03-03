// Include the precompiled headers
#include "pch.h"
#include "Game.h"

// Use some common namespaces to simplify the code
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::UI::Popups;
using namespace Windows::System;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;
using namespace Platform;


// the class definition for the core "framework" of our app
ref class App sealed : public IFrameworkView
{
	bool windowClosed;
	Game game;    // a class to store our game code
public:
	virtual void Initialize(CoreApplicationView^ AppView)
	{
		AppView->Activated += ref new TypedEventHandler
			<CoreApplicationView^, IActivatedEventArgs^>(this, &App::OnActivated);
		CoreApplication::Suspending +=
			ref new EventHandler<SuspendingEventArgs^>(this, &App::Suspending);
		CoreApplication::Resuming +=
			ref new EventHandler<Object^>(this, &App::Resuming);

		windowClosed = false;    // initialize to false
	}
	virtual void SetWindow(CoreWindow^ Window)
	{
		Window->Closed += ref new TypedEventHandler
			<CoreWindow^, CoreWindowEventArgs^>(this, &App::Closed);
	}
	virtual void Load(String^ EntryPoint) {}
	virtual void Run()
	{
		game.Initialize();

		CoreWindow^ Window = CoreWindow::GetForCurrentThread();

		// repeat until window closes
		while (!windowClosed)
		{
			Window->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessAllIfPresent);

			game.Update();
			game.Render();
		}
	}
	virtual void Uninitialize() {}

	void OnActivated(CoreApplicationView^ CoreAppView, IActivatedEventArgs^ Args)
	{
		CoreWindow^ Window = CoreWindow::GetForCurrentThread();
		Window->Activate();
	}

	void Closed(CoreWindow^ sender, CoreWindowEventArgs^ args)
	{
		windowClosed = true;    // time to end the endless loop
	}

	void Suspending(Object^ Sender, SuspendingEventArgs^ Args) {}
	void Resuming(Object^ Sender, Object^ Args) {}
};


// the class definition that creates our core framework
ref class AppSource sealed : IFrameworkViewSource
{
public:
	virtual IFrameworkView^ CreateView()
	{
		return ref new App();    // create the framework view and return it
	}
};

[MTAThread]    // define main() as a multi-threaded-apartment function

// the starting point of all programs
int main(Array<String^>^ args)
{
	CoreApplication::Run(ref new AppSource());    // run the framework view source
	return 0;
}
