#include "plugin.hpp"


struct Bloodmoon : Module {
	enum ParamIds {
		COLORKNOB_PARAM,
		NUM_PARAMS
	};
	enum InputIds {
		SIGNALIN_INPUT,
		NUM_INPUTS
	};
	enum OutputIds {
		SIGNALOUT_OUTPUT,
		NUM_OUTPUTS
	};
	enum LightIds {
		STAR1_LIGHT,
		STAR2_LIGHT,
		STAR3_LIGHT,
		STAR5_LIGHT,
		STAR4_LIGHT,
		NUM_LIGHTS
	};

	Bloodmoon() {
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
		configParam(COLORKNOB_PARAM, 0.f, 1.f, 0.f, "");
	}

	void process(const ProcessArgs& args) override {
	}
};


struct BloodmoonWidget : ModuleWidget {
	BloodmoonWidget(Bloodmoon* module) {
		setModule(module);
		setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/Bloodmoon.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(30.144, 86.545)), module, Bloodmoon::COLORKNOB_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(8.504, 108.184)), module, Bloodmoon::SIGNALIN_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(51.783, 108.184)), module, Bloodmoon::SIGNALOUT_OUTPUT));

		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(10.147, 6.349)), module, Bloodmoon::STAR1_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(44.358, 7.953)), module, Bloodmoon::STAR2_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(56.385, 10.091)), module, Bloodmoon::STAR3_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(53.177, 46.974)), module, Bloodmoon::STAR5_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(5.603, 54.859)), module, Bloodmoon::STAR4_LIGHT));
	}
};


Model* modelBloodmoon = createModel<Bloodmoon, BloodmoonWidget>("Bloodmoon");