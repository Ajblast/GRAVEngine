#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include "GRAVLib/Memory/Singleton.h"

#include "GRAVLib/Concurrency/Jobs/JobManager.h"
#include "GRAVLib/Debug/Instrumentation/Instrumentor.h"
#include "GRAVLib/Debug/Logging/Loggers/LogManager.h"

#include <string>
#include <atomic>
#include <mutex>

namespace GRAVRuntime
{
	class GRAVRuntimeAPI application : public GRAVLib::singleton<application>
	{
	public:
		application();
		application(const std::string& logFilepath);
		virtual ~application();


		void initialize();

		//// Event callback
		//void onEvent(Events::event& event);

		//// Push a layer onto the layer stack
		//void pushLayer(Layers::layer* layer);
		//// Push an overlay
		//void pushOverlay(Layers::layer* overlay);
		//// TODO: Potentially add functionality to pop layers and overlays

		//// Get the current rendering window
		//Rendering::window& getWindow() { return *m_Window; }

		//// Close the application
		//void close();

		//// Get the ImGuiLayer
		//Layers::imguiLayer* getImGuiLayer() { return m_ImGuiLayer; }

		//GRAVLib::scope<Rendering::window> createWindow(bool autoCreateWindow, const std::string& title = "GRAVRuntime Window");

		GRAVLib_SINGLETON_INSTANCE(application);
	private:
		//// Run the application
		//void run();
		//// Run worker thread where everything actually goes
		//void runWorker();
		//// Window close callback
		//bool onWindowClose(Events::windowCloseEvent& event);
		//// Window resize callback
		//bool onWindowResize(Events::windowResizeEvent& event);

	private:
		GRAVLib::scope<GRAVLib::Debug::Logging::logManager> m_LogManager;
		GRAVLib::scope<GRAVLib::Debug::instrumentor> m_Instrumentor;
		GRAVLib::scope<GRAVLib::Concurrency::Jobs::jobManager> m_JobManager;


		//GRAVLib::scope<Rendering::window> m_Window;				// The window associated with the application
		//GRAVLib::scope<GRAVLib::scope<Rendering::window>[]> m_JobWindows;	// Windows for jobs so that jobs will have render context

		//std::atomic_bool m_NeedsRendering;		// Should the rendering occur
		//std::atomic_bool m_Rendered;			// Should the rendering occur
		//std::mutex m_RenderingMutex;			// Condition variable mutex
		//std::condition_variable m_RenderingCV;	// Condition variable for waiting
		//std::atomic_bool m_Running = true;		// Is the application running
		//std::atomic_bool m_Minimized = false;	// Is the application minimized

		//// Job Manager
		//GRAVLib::Concurrency::Jobs::jobManager m_JobManager;					// The job manager for the application
		//GRAVLib::Concurrency::Jobs::jobManagerOptions m_JobManagerOptions;	// Default job manager options

		//float m_LastFrameTime = 0.0f;			// Time to run last frame

		//Layers::layerStack m_LayerStack;		// The update layer stack
		//Layers::imguiLayer* m_ImGuiLayer;		// The ImGuiLayer
	private:
		// Allow the main function to call the private methods, such as run
		//friend int ::main(int argc, char** argv);

	};
}