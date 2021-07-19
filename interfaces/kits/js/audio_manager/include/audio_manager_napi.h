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

#ifndef AUDIO_MNGR_NAPI_H_
#define AUDIO_MNGR_NAPI_H_

#include <iostream>
#include <vector>
#include "audio_svc_manager.h"
#include "napi/native_api.h"
#include "napi/native_node_api.h"

static const std::string AUDIO_MNGR_NAPI_CLASS_NAME = "AudioManager";

class AudioManagerNapi {
public:
    enum AudioVolumeType {
        MEDIA = 1,
        RINGTONE = 2
    };

    enum DeviceFlag {
        OUTPUT_DEVICES_FLAG = 1,
        INPUT_DEVICES_FLAG = 2,
        ALL_DEVICES_FLAG = 3
    };

    static napi_value Init(napi_env env, napi_value exports);

private:
    explicit AudioManagerNapi();
    ~AudioManagerNapi();

    static void Destructor(napi_env env, void* nativeObject, void* finalize_hint);
    static napi_value Construct(napi_env env, napi_callback_info info);
    static napi_value CreateAudioManagerWrapper(napi_env env);
    static napi_value GetAudioManager(napi_env env, napi_callback_info info);
    static napi_value SetVolume(napi_env env, napi_callback_info info);
    static napi_value GetVolume(napi_env env, napi_callback_info info);
    static napi_value GetMaxVolume(napi_env env, napi_callback_info info);
    static napi_value GetMinVolume(napi_env env, napi_callback_info info);
    static napi_value GetDevices(napi_env env, napi_callback_info info);

    static napi_status AddNamedProperty(napi_env env, napi_value object, const char *name, int32_t enumValue);
    static napi_value CreateAudioVolumeTypeObject(napi_env env);
    static napi_value CreateDeviceFlagObject(napi_env env);
    static napi_value CreateDeviceRoleObject(napi_env env);
    static napi_value CreateDeviceTypeObject(napi_env env);

    static napi_ref sConstructor_;
    static napi_ref audioVolumeTypeRef_;
    static napi_ref deviceFlagRef_;
    static napi_ref deviceRoleRef_;
    static napi_ref deviceTypeRef_;

    OHOS::AudioSvcManager *audioMngr_;
    napi_env env_;
    napi_ref wrapper_;
};
#endif /* AUDIO_MNGR_NAPI_H_ */