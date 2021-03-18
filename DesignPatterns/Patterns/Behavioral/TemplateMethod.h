#pragma once

#include <iostream>
#include <vector>

namespace TemplateMethod {

	class Pipeline {
	public:
		void RenderScene(const std::vector<int> meshes) {
			Begin();
			for (auto& mesh : meshes) {
				RenderMesh();
			}
			End();
		}
	protected:
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

	class PipelineOther : public Pipeline {
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

}