#pragma once

#include <iostream>

namespace Strategy {

	struct Pipeline {
		virtual void Begin() {
			std::cout << "Begin!\n";
		};
		virtual void RenderMesh() {
			std::cout << "Rendering...!\n";
		};
		virtual void End() {
			std::cout << "End!\n";
		};
	};

	struct PipelineOther: Pipeline {
		virtual void Begin() override {
			std::cout << "Begin other!\n";
		};
		virtual void RenderMesh() override {
			std::cout << "Rendering other...!\n";
		};
		virtual void End() override {
			std::cout << "End other!\n";
		};
	};

	template<typename T>
	class Renderer {
		static_assert(std::is_base_of<Pipeline, T>::value);

		T pl;
	public:
		explicit Renderer() {}

		void RenderScene(const std::vector<int> meshes) {
			pl.Begin();

			for (auto& mesh : meshes) {
				pl.RenderMesh();
			}

			pl.End();
		}
	};
}