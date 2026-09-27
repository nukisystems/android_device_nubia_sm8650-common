//
// SPDX-FileCopyrightText: The LineageOS Project
// SPDX-License-Identifier: Apache-2.0
//

#include <codec2/hidl/1.0/ComponentStore.h>

// The QTI codec2 service blobs call operator new() for this object with its
// size baked in at their own build time. ComponentStore inherits RefBase
// virtually, so RefBase sits at the end: growing the class moves mRefs past the
// blob's allocation. If this fires, update the size below and repatch the MOVZ
// immediate in extract-files.py to match.
static_assert(
        sizeof(android::hardware::media::c2::V1_0::utils::ComponentStore) == 288,
        "sizeof(ComponentStore) changed; repatch the QTI c2 service blobs");
