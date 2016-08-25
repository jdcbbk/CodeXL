//==============================================================================
// Copyright (c) 2015-2016 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
/// \brief THIS CODE WAS AUTOGENERATED BY PASSTHROUGHGENERATOR ON 08/24/16
//==============================================================================

#include "HSARetCodeAnalyzerHelper.h"

void GetNoReturnCodeAPIs(HSAAPITypeSet& noReturnCodeAPIs)
{
    noReturnCodeAPIs.clear();
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_load_acquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_load_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_store_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_store_release);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_exchange_acq_rel);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_exchange_acquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_exchange_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_exchange_release);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_cas_acq_rel);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_cas_acquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_cas_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_cas_release);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_add_acq_rel);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_add_acquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_add_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_add_release);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_subtract_acq_rel);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_subtract_acquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_subtract_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_subtract_release);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_and_acq_rel);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_and_acquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_and_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_and_release);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_or_acq_rel);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_or_acquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_or_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_or_release);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_xor_acq_rel);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_xor_acquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_xor_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_xor_release);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_wait_acquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_wait_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_load_read_index_acquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_load_read_index_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_load_write_index_acquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_load_write_index_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_store_write_index_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_store_write_index_release);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_cas_write_index_acq_rel);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_cas_write_index_acquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_cas_write_index_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_cas_write_index_release);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_add_write_index_acq_rel);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_add_write_index_acquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_add_write_index_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_add_write_index_release);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_store_read_index_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_store_read_index_release);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_amd_signal_wait_any);

#ifdef FUTURE_ROCR_RELEASE
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_load_scacquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_store_screlease);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_silent_store_screlease);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_exchange_scacq_screl);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_and_scacq_screl);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_subtract_scacquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_or_scacq_screl);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_xor_scacq_screl);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_subtract_scacq_screl);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_add_screlease);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_subtract_screlease);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_or_screlease);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_and_screlease);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_exchange_scacquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_cas_screlease);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_or_scacquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_and_scacquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_silent_store_relaxed);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_xor_scacquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_exchange_screlease);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_wait_scacquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_load_write_index_scacquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_cas_write_index_scacq_screl);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_cas_scacq_screl);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_xor_screlease);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_load_read_index_scacquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_cas_scacquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_cas_write_index_screlease);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_store_write_index_screlease);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_add_write_index_scacq_screl);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_signal_add_scacq_screl);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_add_write_index_scacquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_add_write_index_screlease);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_cas_write_index_scacquire);
    noReturnCodeAPIs.insert(HSA_API_Type_hsa_queue_store_read_index_screlease);
#endif
}
