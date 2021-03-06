// Copyright 2017 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_DATA_HANDLER_INL_H_
#define V8_DATA_HANDLER_INL_H_

#include "src/objects/data-handler.h"

// Has to be the last include (doesn't have include guards):
#include "src/objects/object-macros.h"

namespace v8 {
namespace internal {

bool HeapObject::IsDataHandler() const {
  return IsLoadHandler() || IsStoreHandler();
}

CAST_ACCESSOR(DataHandler)

ACCESSORS(DataHandler, smi_handler, Object, kSmiHandlerOffset)
ACCESSORS(DataHandler, validity_cell, Object, kValidityCellOffset)

int DataHandler::data_field_count() const {
  return (map()->instance_size() - kSizeWithData0) / kPointerSize;
}

ACCESSORS_CHECKED(DataHandler, data1, Object, kData1Offset,
                  map()->instance_size() >= kSizeWithData1)
ACCESSORS_CHECKED(DataHandler, data2, Object, kData2Offset,
                  map()->instance_size() >= kSizeWithData2)

}  // namespace internal
}  // namespace v8

#include "src/objects/object-macros-undef.h"

#endif  // V8_DATA_HANDLER_INL_H_
