// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated with protocol_gen.go -- do not edit this file.
//   go run scripts/protocol_gen/protocol_gen.go
//
// DAP version 1.41.0

#include "dap/protocol.h"

namespace dap {

AttachRequest::AttachRequest() = default;
AttachRequest::~AttachRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(AttachRequest,
                              "attach",
                              DAP_FIELD(restart, "__restart"));

BreakpointLocationsRequest::BreakpointLocationsRequest() = default;
BreakpointLocationsRequest::~BreakpointLocationsRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(BreakpointLocationsRequest,
                              "breakpointLocations",
                              DAP_FIELD(column, "column"),
                              DAP_FIELD(endColumn, "endColumn"),
                              DAP_FIELD(endLine, "endLine"),
                              DAP_FIELD(line, "line"),
                              DAP_FIELD(source, "source"));

CancelRequest::CancelRequest() = default;
CancelRequest::~CancelRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(CancelRequest,
                              "cancel",
                              DAP_FIELD(progressId, "progressId"),
                              DAP_FIELD(requestId, "requestId"));

CompletionsRequest::CompletionsRequest() = default;
CompletionsRequest::~CompletionsRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(CompletionsRequest,
                              "completions",
                              DAP_FIELD(column, "column"),
                              DAP_FIELD(frameId, "frameId"),
                              DAP_FIELD(line, "line"),
                              DAP_FIELD(text, "text"));

ConfigurationDoneRequest::ConfigurationDoneRequest() = default;
ConfigurationDoneRequest::~ConfigurationDoneRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(ConfigurationDoneRequest, "configurationDone");

ContinueRequest::ContinueRequest() = default;
ContinueRequest::~ContinueRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(ContinueRequest,
                              "continue",
                              DAP_FIELD(threadId, "threadId"));

DataBreakpointInfoRequest::DataBreakpointInfoRequest() = default;
DataBreakpointInfoRequest::~DataBreakpointInfoRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(DataBreakpointInfoRequest,
                              "dataBreakpointInfo",
                              DAP_FIELD(name, "name"),
                              DAP_FIELD(variablesReference,
                                        "variablesReference"));

DisassembleRequest::DisassembleRequest() = default;
DisassembleRequest::~DisassembleRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(DisassembleRequest,
                              "disassemble",
                              DAP_FIELD(instructionCount, "instructionCount"),
                              DAP_FIELD(instructionOffset, "instructionOffset"),
                              DAP_FIELD(memoryReference, "memoryReference"),
                              DAP_FIELD(offset, "offset"),
                              DAP_FIELD(resolveSymbols, "resolveSymbols"));

DisconnectRequest::DisconnectRequest() = default;
DisconnectRequest::~DisconnectRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(DisconnectRequest,
                              "disconnect",
                              DAP_FIELD(restart, "restart"),
                              DAP_FIELD(terminateDebuggee,
                                        "terminateDebuggee"));

EvaluateRequest::EvaluateRequest() = default;
EvaluateRequest::~EvaluateRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(EvaluateRequest,
                              "evaluate",
                              DAP_FIELD(context, "context"),
                              DAP_FIELD(expression, "expression"),
                              DAP_FIELD(format, "format"),
                              DAP_FIELD(frameId, "frameId"));

ExceptionInfoRequest::ExceptionInfoRequest() = default;
ExceptionInfoRequest::~ExceptionInfoRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(ExceptionInfoRequest,
                              "exceptionInfo",
                              DAP_FIELD(threadId, "threadId"));

GotoRequest::GotoRequest() = default;
GotoRequest::~GotoRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(GotoRequest,
                              "goto",
                              DAP_FIELD(targetId, "targetId"),
                              DAP_FIELD(threadId, "threadId"));

GotoTargetsRequest::GotoTargetsRequest() = default;
GotoTargetsRequest::~GotoTargetsRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(GotoTargetsRequest,
                              "gotoTargets",
                              DAP_FIELD(column, "column"),
                              DAP_FIELD(line, "line"),
                              DAP_FIELD(source, "source"));

InitializeRequest::InitializeRequest() = default;
InitializeRequest::~InitializeRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(
    InitializeRequest,
    "initialize",
    DAP_FIELD(adapterID, "adapterID"),
    DAP_FIELD(clientID, "clientID"),
    DAP_FIELD(clientName, "clientName"),
    DAP_FIELD(columnsStartAt1, "columnsStartAt1"),
    DAP_FIELD(linesStartAt1, "linesStartAt1"),
    DAP_FIELD(locale, "locale"),
    DAP_FIELD(pathFormat, "pathFormat"),
    DAP_FIELD(supportsMemoryReferences, "supportsMemoryReferences"),
    DAP_FIELD(supportsProgressReporting, "supportsProgressReporting"),
    DAP_FIELD(supportsRunInTerminalRequest, "supportsRunInTerminalRequest"),
    DAP_FIELD(supportsVariablePaging, "supportsVariablePaging"),
    DAP_FIELD(supportsVariableType, "supportsVariableType"));

LaunchRequest::LaunchRequest() = default;
LaunchRequest::~LaunchRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(LaunchRequest,
                              "launch",
                              DAP_FIELD(restart, "__restart"),
                              DAP_FIELD(noDebug, "noDebug"));

LoadedSourcesRequest::LoadedSourcesRequest() = default;
LoadedSourcesRequest::~LoadedSourcesRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(LoadedSourcesRequest, "loadedSources");

ModulesRequest::ModulesRequest() = default;
ModulesRequest::~ModulesRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(ModulesRequest,
                              "modules",
                              DAP_FIELD(moduleCount, "moduleCount"),
                              DAP_FIELD(startModule, "startModule"));

NextRequest::NextRequest() = default;
NextRequest::~NextRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(NextRequest,
                              "next",
                              DAP_FIELD(granularity, "granularity"),
                              DAP_FIELD(threadId, "threadId"));

PauseRequest::PauseRequest() = default;
PauseRequest::~PauseRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(PauseRequest,
                              "pause",
                              DAP_FIELD(threadId, "threadId"));

ReadMemoryRequest::ReadMemoryRequest() = default;
ReadMemoryRequest::~ReadMemoryRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(ReadMemoryRequest,
                              "readMemory",
                              DAP_FIELD(count, "count"),
                              DAP_FIELD(memoryReference, "memoryReference"),
                              DAP_FIELD(offset, "offset"));

RestartFrameRequest::RestartFrameRequest() = default;
RestartFrameRequest::~RestartFrameRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(RestartFrameRequest,
                              "restartFrame",
                              DAP_FIELD(frameId, "frameId"));

RestartRequest::RestartRequest() = default;
RestartRequest::~RestartRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(RestartRequest, "restart");

ReverseContinueRequest::ReverseContinueRequest() = default;
ReverseContinueRequest::~ReverseContinueRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(ReverseContinueRequest,
                              "reverseContinue",
                              DAP_FIELD(threadId, "threadId"));

RunInTerminalRequest::RunInTerminalRequest() = default;
RunInTerminalRequest::~RunInTerminalRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(RunInTerminalRequest,
                              "runInTerminal",
                              DAP_FIELD(args, "args"),
                              DAP_FIELD(cwd, "cwd"),
                              DAP_FIELD(env, "env"),
                              DAP_FIELD(kind, "kind"),
                              DAP_FIELD(title, "title"));

ScopesRequest::ScopesRequest() = default;
ScopesRequest::~ScopesRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(ScopesRequest,
                              "scopes",
                              DAP_FIELD(frameId, "frameId"));

SetBreakpointsRequest::SetBreakpointsRequest() = default;
SetBreakpointsRequest::~SetBreakpointsRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(SetBreakpointsRequest,
                              "setBreakpoints",
                              DAP_FIELD(breakpoints, "breakpoints"),
                              DAP_FIELD(lines, "lines"),
                              DAP_FIELD(source, "source"),
                              DAP_FIELD(sourceModified, "sourceModified"));

SetDataBreakpointsRequest::SetDataBreakpointsRequest() = default;
SetDataBreakpointsRequest::~SetDataBreakpointsRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(SetDataBreakpointsRequest,
                              "setDataBreakpoints",
                              DAP_FIELD(breakpoints, "breakpoints"));

SetExceptionBreakpointsRequest::SetExceptionBreakpointsRequest() = default;
SetExceptionBreakpointsRequest::~SetExceptionBreakpointsRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(SetExceptionBreakpointsRequest,
                              "setExceptionBreakpoints",
                              DAP_FIELD(exceptionOptions, "exceptionOptions"),
                              DAP_FIELD(filters, "filters"));

SetExpressionRequest::SetExpressionRequest() = default;
SetExpressionRequest::~SetExpressionRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(SetExpressionRequest,
                              "setExpression",
                              DAP_FIELD(expression, "expression"),
                              DAP_FIELD(format, "format"),
                              DAP_FIELD(frameId, "frameId"),
                              DAP_FIELD(value, "value"));

SetFunctionBreakpointsRequest::SetFunctionBreakpointsRequest() = default;
SetFunctionBreakpointsRequest::~SetFunctionBreakpointsRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(SetFunctionBreakpointsRequest,
                              "setFunctionBreakpoints",
                              DAP_FIELD(breakpoints, "breakpoints"));

SetInstructionBreakpointsRequest::SetInstructionBreakpointsRequest() = default;
SetInstructionBreakpointsRequest::~SetInstructionBreakpointsRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(SetInstructionBreakpointsRequest,
                              "setInstructionBreakpoints",
                              DAP_FIELD(breakpoints, "breakpoints"));

SetVariableRequest::SetVariableRequest() = default;
SetVariableRequest::~SetVariableRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(SetVariableRequest,
                              "setVariable",
                              DAP_FIELD(format, "format"),
                              DAP_FIELD(name, "name"),
                              DAP_FIELD(value, "value"),
                              DAP_FIELD(variablesReference,
                                        "variablesReference"));

SourceRequest::SourceRequest() = default;
SourceRequest::~SourceRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(SourceRequest,
                              "source",
                              DAP_FIELD(source, "source"),
                              DAP_FIELD(sourceReference, "sourceReference"));

StackTraceRequest::StackTraceRequest() = default;
StackTraceRequest::~StackTraceRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(StackTraceRequest,
                              "stackTrace",
                              DAP_FIELD(format, "format"),
                              DAP_FIELD(levels, "levels"),
                              DAP_FIELD(startFrame, "startFrame"),
                              DAP_FIELD(threadId, "threadId"));

StepBackRequest::StepBackRequest() = default;
StepBackRequest::~StepBackRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(StepBackRequest,
                              "stepBack",
                              DAP_FIELD(granularity, "granularity"),
                              DAP_FIELD(threadId, "threadId"));

StepInRequest::StepInRequest() = default;
StepInRequest::~StepInRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(StepInRequest,
                              "stepIn",
                              DAP_FIELD(granularity, "granularity"),
                              DAP_FIELD(targetId, "targetId"),
                              DAP_FIELD(threadId, "threadId"));

StepInTargetsRequest::StepInTargetsRequest() = default;
StepInTargetsRequest::~StepInTargetsRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(StepInTargetsRequest,
                              "stepInTargets",
                              DAP_FIELD(frameId, "frameId"));

StepOutRequest::StepOutRequest() = default;
StepOutRequest::~StepOutRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(StepOutRequest,
                              "stepOut",
                              DAP_FIELD(granularity, "granularity"),
                              DAP_FIELD(threadId, "threadId"));

TerminateRequest::TerminateRequest() = default;
TerminateRequest::~TerminateRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(TerminateRequest,
                              "terminate",
                              DAP_FIELD(restart, "restart"));

TerminateThreadsRequest::TerminateThreadsRequest() = default;
TerminateThreadsRequest::~TerminateThreadsRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(TerminateThreadsRequest,
                              "terminateThreads",
                              DAP_FIELD(threadIds, "threadIds"));

ThreadsRequest::ThreadsRequest() = default;
ThreadsRequest::~ThreadsRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(ThreadsRequest, "threads");

VariablesRequest::VariablesRequest() = default;
VariablesRequest::~VariablesRequest() = default;
DAP_IMPLEMENT_STRUCT_TYPEINFO(VariablesRequest,
                              "variables",
                              DAP_FIELD(count, "count"),
                              DAP_FIELD(filter, "filter"),
                              DAP_FIELD(format, "format"),
                              DAP_FIELD(start, "start"),
                              DAP_FIELD(variablesReference,
                                        "variablesReference"));

}  // namespace dap
