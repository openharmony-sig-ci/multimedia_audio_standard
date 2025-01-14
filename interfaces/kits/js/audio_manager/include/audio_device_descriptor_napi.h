/*
 * Copyright (C) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AUDIO_DEVICE_DESCRIPTOR_NAPI_H_
#define AUDIO_DEVICE_DESCRIPTOR_NAPI_H_

#include <iostream>
#include <vector>
#include "audio_system_manager.h"
#include "napi/native_api.h"
#include "napi/native_node_api.h"

namespace OHOS {
namespace AudioStandard {
static const std::string AUDIO_DEVICE_DESCRIPTOR_NAPI_CLASS_NAME = "AudioDeviceDescriptor";

class AudioDeviceDescriptorNapi {
public:
    AudioDeviceDescriptorNapi();
    ~AudioDeviceDescriptorNapi();

    enum DeviceType {
        INVALID = 0,
        SPEAKER = 1,
        WIRED_HEADSET = 2,
        BLUETOOTH_SCO = 3,
        BLUETOOTH_A2DP = 4,
        MIC = 5
    };

    enum DeviceRole {
        INPUT_DEVICE = 1,
        OUTPUT_DEVICE = 2
    };

    static napi_value Init(napi_env env, napi_value exports);
    static napi_value CreateAudioDeviceDescriptorWrapper(napi_env env,
        sptr<AudioDeviceDescriptor> deviceDescriptor);

private:
    static void Destructor(napi_env env, void* nativeObject, void* finalize_hint);
    static napi_value Construct(napi_env env, napi_callback_info info);
    static napi_value GetDeviceRole(napi_env env, napi_callback_info info);
    static napi_value GetDeviceType(napi_env env, napi_callback_info info);

    static napi_ref sConstructor_;
    static sptr<AudioDeviceDescriptor> sAudioDescriptor_;

    sptr<AudioDeviceDescriptor> audioDescriptor_;
    napi_env env_;
    napi_ref wrapper_;
};
} // namespace AudioStandard
} // namespace OHOS
#endif /* AUDIO_DEVICE_DESCRIPTOR_NAPI_H_ */
