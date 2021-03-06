//
// Copyright © 2017 Arm Ltd. All rights reserved.
// See LICENSE file in the project root for full license information.
//

#pragma once

#include "backends/ClWorkloadUtils.hpp"


namespace armnn
{

class ClConvolution2dUint8Workload : public Uint8Workload<Convolution2dQueueDescriptor>
{
public:
    ClConvolution2dUint8Workload(const Convolution2dQueueDescriptor& descriptor, const WorkloadInfo& info);
    void Execute() const override;

private:
    mutable std::unique_ptr<arm_compute::IFunction>         m_pConvolutionLayer;

    arm_compute::CLTensor m_KernelTensor;
    arm_compute::CLTensor m_BiasTensor;
};

} //namespace armnn

