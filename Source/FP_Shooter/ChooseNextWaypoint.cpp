// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrollingGuard.h"
#include "AIController.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent * BlackBoardComponent = OwnerComp.GetBlackboardComponent();
	int32 Index = BlackBoardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
	auto AIOwner = OwnerComp.GetAIOwner();
	APatrollingGuard * Patrol = Cast<APatrollingGuard>(AIOwner->GetControlledPawn());
	int32 PatrolPointsNumber = Patrol->PatrolPoints.Num();
	if (PatrolPointsNumber == 0) return EBTNodeResult::Failed;
	BlackBoardComponent->SetValueAsObject(Waypoint.SelectedKeyName, Patrol->PatrolPoints[Index++ % PatrolPointsNumber]);
	
	BlackBoardComponent->SetValueAsInt(IndexKey.SelectedKeyName, Index % PatrolPointsNumber);
	//UE_LOG(LogTemp, Warning, TEXT("Execute task of UChooseNextWaypoint %i"), Index);
	return EBTNodeResult::Succeeded;
}
